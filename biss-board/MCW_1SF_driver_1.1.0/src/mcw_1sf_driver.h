/**
 ******************************************************************************
 * @file    mcw_1sf_driver.h
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

#ifndef MCW_1SF_DRIVER_H
#define MCW_1SF_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @defgroup Wrapper_Functions
 * @brief Functions declared as `extern` have to be defined by the user according to the specific hardware used.
 *
 * @note The definition of those functions is mandatory to use this driver.
 * @{
 */
/**
 * @brief This function is a wrapper to be defined with the MCU-specific SPI-transmit-receive-function.
 *
 * @param data_tx is a pointer to the data buffer that is transmitted.
 * @param data_rx is a pointer to the buffer the received data is written to.
 * @param datasize is the length of all bytes transmitted.
 * @retval None
 */
extern void mcw_spi_transfer(uint8_t *data_tx, uint8_t *data_rx, uint16_t datasize);
/**
 * @}
 */

/**
 * @defgroup MCW_Info_Byte
 * @brief Possible content of the info byte received when calling function @ref mcw_read_frame_data.
 * @{
 */
enum MCW_INFO_BYTE {
	MR3_INFO_BYTE_NO_DATA = 0x00,
	MR3_INFO_BYTE_FRAME_LENGTH_MIN = 0x01,
	MR3_INFO_BYTE_FRAME_LENGTH_MAX = 0xFA,
	MR3_INFO_BYTE_LENGTH_ERROR = 0xFB,
	MR3_INFO_BYTE_NO_CDS = 0xFC,
	MR3_INFO_BYTE_FRAME_ERROR = 0xFD,
	MR3_INFO_BYTE_BANK_BUSY = 0xFE,
	MR3_INFO_BYTE_NO_FRAME = 0xFF,
};
/**
 * @}
 */

/**
 * @defgroup MCW_Parameters
 * @{
 */
/**
 * @addtogroup MCW_Parameters_Struct
 * @brief Structure implemented to represent iC-MCW parameters.
 * @{
 */
struct mcw_param {
	uint8_t addr;
	uint8_t pos;
	uint8_t len;
};
/**
 * @}
 */

/**
 * @addtogroup MCW_Parameters_List
 * @brief List of parameters according to iC-MCW register map represented as @ref MCW_Parameters_Struct.
 * @{
 */
/* Chip Revision */
extern const struct mcw_param MCW_CHIP_REV;

/* Device Status */
extern const struct mcw_param MCW_STATE;
extern const struct mcw_param MCW_DETECT;
extern const struct mcw_param MCW_AVAIL;

/* Device Error */
extern const struct mcw_param MCW_RST;
extern const struct mcw_param MCW_HFRAME;
extern const struct mcw_param MCW_WRITE;
extern const struct mcw_param MCW_READ;
extern const struct mcw_param MCW_OPCODE;
extern const struct mcw_param MCW_PLL;
extern const struct mcw_param MCW_SFRAME;

/* Frame Information */
extern const struct mcw_param MCW_INFO;

/* Frame Number CD */
extern const struct mcw_param MCW_FNUM;
extern const struct mcw_param MCW_NCDM;
extern const struct mcw_param MCW_CDS;

/* Frame Error */
extern const struct mcw_param MCW_WARN;
extern const struct mcw_param MCW_CODE;

/* BiSS Measurement */
extern const struct mcw_param MCW_C_TIME;
extern const struct mcw_param MCW_L_DELAY;
extern const struct mcw_param MCW_P_TIME;
/**
 * @}
 */

/**
 * @}
 */

/**
 * @defgroup MCW_Functions
 * @{
 */
/**
 * @addtogroup MCW_Functions_Basic
 * @brief Functions according to iC-MCW SPI opcodes.
 * @{
 */
void mcw_read_status(uint8_t *status);
void mcw_read_frame_data(uint8_t *info, uint8_t *err_code, uint8_t frame_data[32], uint8_t optional_bytes[6]);
void mcw_read_register(uint8_t start_addr, uint8_t *status, uint8_t *data_rx, uint8_t datasize);
void mcw_write_register(uint8_t *status);
/**
 * @}
 */

/**
 * @addtogroup MCW_Functions_Advanced
 * @brief Functions going through a sequence of @ref MCW_Functions_Basic with enhanced data handling.
 * @{
 */
uint16_t mcw_read_param(const struct mcw_param *param);
/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* MCW_1SF_DRIVER_H */
