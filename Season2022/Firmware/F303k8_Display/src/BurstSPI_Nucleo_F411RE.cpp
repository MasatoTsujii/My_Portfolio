/*
    Only tested with a Ili9341 TFT on a Nucleo F411RE board.
    -James Kidd
*/ 

/* BurstSPI_NUCLEO_F411RE.cpp */
#ifdef TARGET_NUCLEO_F411RE
#include "BurstSPI.h"

static SPI_HandleTypeDef SpiHandle;

void BurstSPI::fastWrite(int data) {
    SpiHandle.Instance = (SPI_TypeDef *)(_spi.spi);
    while (!((__HAL_SPI_GET_FLAG(&SpiHandle, SPI_FLAG_TXE) != RESET) ? 1 : 0));
    SpiHandle.Instance->DR =(uint16_t)data;
    }
    
void BurstSPI::clearRX( void ) {
    SpiHandle.Instance = (SPI_TypeDef *)(_spi.spi);
    //wait till SPI is not busy
    while(__HAL_SPI_GET_FLAG(&SpiHandle, SPI_FLAG_BSY) != RESET);    
    //Loop while data in RX, may not be needed     
    while(__HAL_SPI_GET_FLAG(&SpiHandle, SPI_FLAG_RXNE) != RESET){
        int dummy = SpiHandle.Instance->DR;
    }
}
#endif
