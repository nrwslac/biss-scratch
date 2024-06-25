#include "SPI.h"

static uint8_t buf_tx[0xFF + 0x2];
static uint8_t buf_rx[0xFF + 0x2];

void SPI_Init(){
    SPI0_C1 |= SPI_C1_SPE_MASK;
    SPI0_C1 |= SPI_C1_MSTR_MASK;

    SPI0_BR |= SPI_BR_SPPR_MASK;
    SPI0_BR |= SPI_BR_SPR_MASK;
}

void SPI_Transmit(uint8_t buf_rx, uint8_t buf_tx){
}
