/*****************************************************************************
* Module     : EEPROM driver
* File Name  : EEPROM.h
* Description: header file for the EEPROM driver
* Author     : Kariman Karam
* Date       : 26/7/2021
******************************************************************************/

#ifndef ECUAL_EEPROM_DRIVER_EEPROM_H_
#define ECUAL_EEPROM_DRIVER_EEPROM_H_

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/BIT_math.h"
#include "../../LIB/Data_types.h"
#include "../../MCAL/I2C/I2C.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
enuErrorStatus_t EEPROM_init(void);
enuErrorStatus_t EEPROM_writeByte(uintt16_t u16Address, uint8_t u8Data);
enuErrorStatus_t EEPROM_readByte(uintt16_t u16Address, uint8_t *pu8Data);
#endif /* ECUAL_EEPROM_DRIVER_EEPROM_H_ */
