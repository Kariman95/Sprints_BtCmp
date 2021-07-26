/*****************************************************************************
* Module     : I2C(TWI)
* File Name  : I2C.h
* Description: Header file for the I2C(TWI) AVR driver
* Author     : Kariman Karam
* Date       : 25/7/2021
******************************************************************************/


#ifndef I2C_H_
#define I2C_H_

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/Data_types.h"
#include "../../LIB/BIT_math.h"
#include "I2C_registers.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start 
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the TWI matser
*************************************************************************************************/
enuErrorStatus_t TWI_initMatser(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the TWI slave
*************************************************************************************************/
enuErrorStatus_t TWI_initSlave(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit start condition
*************************************************************************************************/
enuErrorStatus_t TWI_start(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit repeated start condition
*************************************************************************************************/
enuErrorStatus_t TWI_repeatedStart(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit stop condition
*************************************************************************************************/
enuErrorStatus_t TWI_stop(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit data
*************************************************************************************************/
enuErrorStatus_t TWI_writeData(uint8_t u8Data);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit address
*************************************************************************************************/
enuErrorStatus_t TWI_writeAddress(uint8_t u8Address);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to read data from slave with ACK
*************************************************************************************************/
enuErrorStatus_t TWI_readDataWithACK(uint8_t* pu8Data);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to read data from slave with NACK
*************************************************************************************************/
enuErrorStatus_t TWI_readDataWithNACK(uint8_t* pu8Data);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to get the status of the transmission
*************************************************************************************************/
uint8_t TWI_getStatus(void);

#endif /* I2C_H_ */
