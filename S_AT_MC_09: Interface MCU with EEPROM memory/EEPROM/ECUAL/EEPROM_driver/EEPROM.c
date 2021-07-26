/*****************************************************************************
* Module     : EEPROM driver
* File Name  : EEPROM.c
* Description: Source file for the EEPROM driver
* Author     : Kariman Karam
* Date       : 26/7/2021
******************************************************************************/

#include "EEPROM.h"

enuErrorStatus_t EEPROM_init(void)
{
	/* just initialize the I2C(TWI) module inside the MC */
	if(TWI_initMatser()==E_ERROR && TWI_initSlave()==E_ERROR)
	{
		return E_ERROR;
	}

	return E_OK;
}//end EEPROM_init

enuErrorStatus_t EEPROM_writeByte(uintt16_t u16Address, uint8_t u8Data)
{
	/* Send the Start Bit */
    if(TWI_start()==E_ERROR)
    {
    	return E_ERROR;
    }

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    if(TWI_writeData((uint8_t)((0xA0) | ((u16Address & 0x0700)>>7))))
    {
    	return E_ERROR;
    }

    /* Send the required memory location address */
    if(TWI_writeData((uint8_t)(u16Address))==E_ERROR)
    {
    	return E_ERROR;
    }

    /* write byte to eeprom */
    if(TWI_writeData(u8Data)==E_ERROR)
    {
    	return E_ERROR;
    }
    /* Send the Stop Bit */
    TWI_stop();

    return E_OK;
}//end EEPROM_writeByte

enuErrorStatus_t EEPROM_readByte(uintt16_t u16Address, uint8_t *pu8Data)
{
	/* Send the Start Bit */
    if(TWI_start()==E_ERROR)
    {
    	return E_ERROR;
    }

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    if(TWI_writeData((uint8_t)((0xA0) | ((u16Address & 0x0700)>>7))))
    {
      	return E_ERROR;
    }
    /* Send the required memory location address */
    if(TWI_writeData((uint8_t)(u16Address))==E_ERROR)
    {
    	return E_ERROR;
    }

    /* Send the Repeated Start Bit */
    if(TWI_repeatedStart()==E_ERROR)
    {
    	return E_ERROR;
    }

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    if(TWI_writeData((uint8_t)((0xA0) | ((u16Address & 0x0700)>>7)| 1)))
    {
		return E_ERROR;
	}

    /* Read Byte from Memory without send ACK */
    if(TWI_readDataWithNACK(pu8Data)==E_ERROR)
    {
    	return E_ERROR;
    }

    /* Send the Stop Bit */
    TWI_stop();

    return E_OK;
}//end EEPROM_readByte
