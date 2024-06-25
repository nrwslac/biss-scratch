/**
 ******************************************************************************
 * @file    mcw_1sf_driver.c
 * @author  iC-Haus GmbH
 * @version 1.1.0
 * @note Designed according to iC-MCW datasheet release C1 for chip revision Y.
 ******************************************************************************
 * @attention
 *
 *	Software and its documentation is provided by iC-Haus GmbH or contributors "AS IS" and is
 *	subject to the ZVEI General Conditions for the Supply of Products and Services with iC-Haus
 *	amendments and the ZVEI Software clause with iC-Haus amendments (http://www.ichaus.de/EULA).
 *
 ******************************************************************************
 */

#include "mcw_1sf_driver.h"

/* iC-MCW opcodes */
enum MCW_OPCODE_enum {
	MCW_OPCODE_READ_STATUS = 0x9C,
	MCW_OPCODE_READ_FRAME_DATA = 0xA6,
	MCW_OPCODE_READ_REGISTER = 0x8A,
	MCW_OPCODE_WRITE_REGISTER = 0xD2,
};

/* iC-MCW parameters */
const struct mcw_param MCW_CHIP_REV = { .addr = 0x00, .pos = 7, .len = 8 };

const struct mcw_param MCW_STATE = { .addr = 0x01, .pos = 2, .len = 3 };
const struct mcw_param MCW_DETECT = { .addr = 0x01, .pos = 3, .len = 1 };
const struct mcw_param MCW_AVAIL = { .addr = 0x01, .pos = 4, .len = 1 };

const struct mcw_param MCW_RST = { .addr = 0x02, .pos = 0, .len = 1 };
const struct mcw_param MCW_HFRAME = { .addr = 0x02, .pos = 1, .len = 1 };
const struct mcw_param MCW_WRITE = { .addr = 0x02, .pos = 2, .len = 1 };
const struct mcw_param MCW_READ = { .addr = 0x02, .pos = 3, .len = 1 };
const struct mcw_param MCW_OPCODE = { .addr = 0x02, .pos = 4, .len = 1 };
const struct mcw_param MCW_PLL = { .addr = 0x02, .pos = 6, .len = 1 };
const struct mcw_param MCW_SFRAME = { .addr = 0x02, .pos = 7, .len = 1 };

const struct mcw_param MCW_INFO = { .addr = 0x03, .pos = 7, .len = 8 };

const struct mcw_param MCW_FNUM = { .addr = 0x05, .pos = 5, .len = 14 };
const struct mcw_param MCW_NCDM = { .addr = 0x05, .pos = 6, .len = 1 };
const struct mcw_param MCW_CDS = { .addr = 0x05, .pos = 7, .len = 1 };

const struct mcw_param MCW_WARN = { .addr = 0x06, .pos = 0, .len = 1 };
const struct mcw_param MCW_CODE = { .addr = 0x06, .pos = 2, .len = 2 };

const struct mcw_param MCW_C_TIME = { .addr = 0x0D, .pos = 4, .len = 13 };
const struct mcw_param MCW_L_DELAY = { .addr = 0x0E, .pos = 6, .len = 10 };
const struct mcw_param MCW_P_TIME = { .addr = 0x0F, .pos = 7, .len = 9 };

/* iC-MCW Defines */
#define MCW_REGISTER_SIZE	8

/* local function declarations */
static uint8_t get_start_bit_number(uint8_t bit_pos, uint8_t bit_len);

/* globals */
static uint8_t buf_tx[0xFF + 0x2];
static uint8_t buf_rx[0xFF + 0x2];
static uint16_t bufsize;

/**
 * @brief This function is used to latch and read the status byte.
 *
 * @param status is a pointer to a byte the received status byte is written to.
 * @retval None
 */
void mcw_read_status(uint8_t *status) {
	bufsize = 2;
	buf_tx[0] = MCW_OPCODE_READ_STATUS;
	buf_tx[1] = 0;

	mcw_spi_transfer(buf_tx, buf_rx, bufsize);

	*status = buf_rx[1];
}

/**
 * @brief This function is used to read the last completely processed BiSS Frame.
 *
 * @param info is a pointer to a buffer the received info byte is written to.
 * @param err_code is a pointer to a buffer the received frame error byte is written to (if available).
 * @param frame_data is a buffer the received frame data is written to (if available).
 * @param optional_bytes is a buffer the received optional bytes are written to.
 * @retval None
 */
void mcw_read_frame_data(uint8_t *info, uint8_t *err_code, uint8_t frame_data[32], uint8_t optional_bytes[6]) {
	bufsize = 40;
	buf_tx[0] = MCW_OPCODE_READ_FRAME_DATA;

	for (uint8_t i = 1; i < bufsize; i++) {
		buf_tx[i] = 0;
	}

	mcw_spi_transfer(buf_tx, buf_rx, bufsize);

	*info = buf_rx[1];

	uint8_t frame_length = 0;
	uint8_t frame_bytes = 0;
	*err_code = 0;

	if ((*info >= MR3_INFO_BYTE_FRAME_LENGTH_MIN) && (*info <= MR3_INFO_BYTE_FRAME_LENGTH_MAX)) {
		frame_length = *info;
	}
	else if (*info == MR3_INFO_BYTE_LENGTH_ERROR) {
		frame_length = 250;
	}
	else if (*info == MR3_INFO_BYTE_FRAME_ERROR){
		*err_code = buf_rx[2];
	}

	if (frame_length != 0) {
		frame_bytes = frame_length >> 3;

		if ((frame_length % 8 ) != 0) {
			frame_bytes++;
		}

		for (uint8_t i = 0; i < frame_bytes; i++) {
			frame_data[i] = buf_rx[i + 2];
		}
	}

	for (uint8_t i = 0; i < 6; i++) {
		if (*info == MR3_INFO_BYTE_FRAME_ERROR) {
			optional_bytes[i] = buf_rx[i + 3];
		}
		else {
			optional_bytes[i] = buf_rx[i + 2 + frame_bytes];
		}
	}
}


/**
 * @brief This function is used to read data from one or multiple registers.
 *
 * @param start_addr is the address of the first register to start reading from.
 * @param status is a pointer to a byte the received status byte is written to.
 * @param data_rx is a pointer to a buffer the received data is written to.
 * @param datasize is the number of registers to be read from.
 * @retval None
 */
void mcw_read_register(uint8_t start_addr, uint8_t *status, uint8_t *data_rx, uint8_t datasize) {
	bufsize = datasize + 2;
	buf_tx[0] = MCW_OPCODE_READ_REGISTER;
	buf_tx[1] = start_addr;

	for (uint8_t i = 0; i < datasize; i++) {
		buf_tx[i + 2] = 0;
	}

	mcw_spi_transfer(buf_tx, buf_rx, bufsize);

	*status = buf_rx[1];

	for (uint8_t i = 0; i < datasize; i++)
		data_rx[i] = buf_rx[i + 2];
}

/**
 * @brief This function is used to reset the error bits in register DeviceError at address 0x02.
 *
 * @param status is a pointer to a byte the received status byte is written to.
 * @retval None
 */
void mcw_write_register(uint8_t *status) {
	bufsize = 3;
	buf_tx[0] = MCW_OPCODE_WRITE_REGISTER;
	buf_tx[1] = 0x02;
	buf_tx[2] = 0;

	mcw_spi_transfer(buf_tx, buf_rx, bufsize);

	*status = buf_rx[1];
}

/**
  * @brief This function reads a specific chip parameter.
  *
  * @param param has to be one of the parameters defined in @ref MCW_Parameters_List.
  * @retval Value of the parameter read.
  */
uint16_t mcw_read_param(const struct mcw_param *param) {
	uint8_t datasize = 0;

	if (param->len <= 8) {
		datasize = 1;
	}
	else {
		datasize = 2;
	}

	uint8_t start_bit = get_start_bit_number(param->pos, param->len);
	uint8_t start_addr = param->addr - datasize + 1;
	uint8_t data_rx[2] = {0, 0};
	uint8_t status;

	mcw_read_register(start_addr, &status, data_rx, datasize);

	uint16_t param_val = 0;
	for (int8_t i = datasize - 1; i >= 0; i--) {
		param_val <<= 8;
		param_val |= data_rx[i];
	}

	param_val >>= start_bit;

	uint16_t param_mask = 0;
	for (uint8_t j = 0; j < param->len; j++)
		param_mask |= 1 << j;

	param_val &= param_mask;

	return param_val;
}

/* local function definitions */
static uint8_t get_start_bit_number(uint8_t bit_pos, uint8_t bit_len) {
	if(bit_len <= 8) {
		return (bit_pos - bit_len + 1);
	}

	return (MCW_REGISTER_SIZE - (bit_len - bit_pos - 1));
}
