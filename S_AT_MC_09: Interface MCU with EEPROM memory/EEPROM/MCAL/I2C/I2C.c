/*****************************************************************************
* Module     : I2C(TWI)
* File Name  : I2C.c
* Description: Source file for the I2C(TWI) AVR driver
* Author     : Kariman Karam
* Date       : 25/7/2021
******************************************************************************/

#include "I2C.h"

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the TWI matser
*************************************************************************************************/
enuErrorStatus_t TWI_initMatser(void)
{
	//prescaller = 1
	CLR_BIT(TWSR_R,TWPS1_B);
	CLR_BIT(TWSR_R,TWPS0_B);

	//prescaller = 64
//	SET_BIT(TWSR_R,TWPS1_B);
//	SET_BIT(TWSR_R,TWPS0_B);
//	TWSR_R |= 1<<TWPS1_B | 1<<TWPS1_B;

	/* Bit Rate: 100.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
	TWBR_R = 32;

	return E_OK;
}//end TWI_initMatser

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the TWI slave
*************************************************************************************************/
enuErrorStatus_t TWI_initSlave(void)
{
	//set the address of the slave to be 0x01
	TWAR_R = 0x01<<1;

	return E_OK;
}//end TWI_initSlave

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit start condition
*************************************************************************************************/
enuErrorStatus_t TWI_start(void)
{
    /* 
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR_R = (1 << TWINT_B) | (1 << TWSTA_B) | (1 << TWEN_B);
    
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(!GET_BIT(TWCR_R,TWINT_B));

    //check if start bit is transmitted successfully
    if(TWI_getStatus() != TW_START)
    {
    	return E_ERROR;
    }
    return E_OK;
}//end TWI_start

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit repeated start condition
*************************************************************************************************/
enuErrorStatus_t TWI_repeatedStart(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR_R = (1 << TWINT_B) | (1 << TWSTA_B) | (1 << TWEN_B);

    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(!GET_BIT(TWCR_R,TWINT_B));

    //check if start bit is transmitted successfully
    if(TWI_getStatus() != TW_REP_START)
    {
    	return E_ERROR;
    }
    return E_OK;
}//end TWI_start

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit stop condition
*************************************************************************************************/
enuErrorStatus_t TWI_stop(void)
{
    /* 
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR_R = (1 << TWINT_B) | (1 << TWSTO_B) | (1 << TWEN_B);

    return E_OK;
}//end TWI_stop

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit data
*************************************************************************************************/
enuErrorStatus_t TWI_writeData(uint8_t u8Data)
{
    /* Put data On TWI data Register */
    TWDR_R = u8Data;
    /* 
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR_R = (1 << TWINT_B) | (1 << TWEN_B);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(!GET_BIT(TWCR_R,TWINT_B));

    //check if data is transmitted successfully
    if(TWI_getStatus() != TW_MT_DATA_ACK)
    {
    	return E_ERROR;
    }
    return E_OK;
}//end TWI_writeData

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to transmit address
*************************************************************************************************/
enuErrorStatus_t TWI_writeAddress(uint8_t u8Address)
{
    /* Put address On TWI data Register */
    TWDR_R = u8Address<<1;
    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR_R = (1 << TWINT_B) | (1 << TWEN_B);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(!GET_BIT(TWCR_R,TWINT_B));

    //check if address is transmitted successfully
    if(TWI_getStatus() != TW_MT_SLA_W_ACK)
    {
    	return E_ERROR;
    }
    return E_OK;
}//end TWI_writeAddress

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to read data from slave with ACK
*************************************************************************************************/
enuErrorStatus_t TWI_readDataWithACK(uint8_t* pu8Data)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR_R = (1 << TWINT_B) | (1 << TWEN_B) | (1 << TWEA_B);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(!GET_BIT(TWCR_R,TWINT_B));

    /* Read Data */
    *pu8Data = TWDR_R;

    //check if data is received successfully
    if(TWI_getStatus() != TW_MR_DATA_ACK)
    {
    	return E_ERROR;
    }

    /* Read Data */
    *pu8Data = TWDR_R;

    return E_OK;
}//end TWI_readDataWithACK

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to read data from slave with NACK
*************************************************************************************************/
enuErrorStatus_t TWI_readDataWithNACK(uint8_t* pu8Data)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR_R = (1 << TWINT_B) | (1 << TWEN_B);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(!GET_BIT(TWCR_R,TWINT_B));

    //check if data is received successfully
    if(TWI_getStatus() != TW_MR_DATA_NACK)
    {
    	return E_ERROR;
    }

    /* Read Data */
    *pu8Data = TWDR_R;

    return E_OK;
}//end TWI_readDataWithNACK

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to get the status of the transmission
*************************************************************************************************/
uint8_t TWI_getStatus(void)
{
    uint8_t u8Status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    u8Status = TWSR_R & 0xF8;
    return u8Status;
}//end TWI_getStatus
