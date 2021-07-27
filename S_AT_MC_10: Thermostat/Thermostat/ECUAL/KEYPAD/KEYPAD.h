/*****************************************************************************
* Module     : KEYPAD
* File Name  : KEYPAD.h
* Description: Header file for the Keypad driver
* Author     : Kariman Karam
* Date       : 23/7/2021
******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/BIT_math.h"
#include "../../LIB/Data_types.h"
#include "../../MCAL/DIO/DIO_cfg.h"
#include "../../MCAL/DIO/DIO_init.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : Function responsible for getting the pressed keypad key
*************************************************************************************************/
enuErrorStatus_t KeyPad_getPressedKey(uint8_t* u8Key);

#endif /* KEYPAD_H_ */
