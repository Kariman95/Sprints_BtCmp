/*
 * TM_Int.h
 *
 *  Created on: Jul 10, 2021
 *      Author: Kariman
 */

#ifndef MCAL_TIMER_TM_INT_H_
#define MCAL_TIMER_TM_INT_H_
//
///*- INCLUDES -----------------------------------------------*/
//#include "../../LIB/Data_types.h"
//#include "../../LIB/BIT_math.h"
//#include "TM_Cfg.h"
//
///*- ENUMS --------------------------------------------------*/
//typedef enum {TIMER0, TIMER1, TIMER2} enuTimerModule_t;
//typedef enum {NORMAL, CTC, FAST_PWM, PC_PWM} enuTimerMode_t;
//typedef enum {NO_CLOCK, NO_PRESCALER, PRESCALER_8, PRESCALER_64, PRESCALER_256, PRESCALER_1024,
//			  EXTERNAL_CLOCK_FALL_EDGE, EXTERNAL_CLOCK_RISE_EDGE, PRESCALER_32, PRESCALER_128} enuTimerClock_t;
//typedef enum {TIMER_INT_DIS, TIMER_INT_EN} enuTimerIntEn_t;
//
///*- STRUCTS -----------------------------------------------*/
//typedef struct
//{
//	/* Selecting the used timer module */
//	enuTimerModule_t enuTimerModule;
//	/* Selecting the timer module mode */
//	enuTimerMode_t   enuTimerMode;
//	/* Selecting the clock source to be used for the selected module							*
//	 * N.B: 1) TIMER0 and TIMER1 don't support PRESCALER_32 and PRESCALER_128 modes				*
//	 *		2) TIMER2 don't support EXTERNAL_CLOCK_FALL_EDGE and EXTERNAL_CLOCK_FALL_EDGE modes */
//	enuTimerClock_t  enuTimerClock;
//	/* Selecting whether to enable or disable timer module interrupts */
//	enuTimerIntEn_t  enuTimerIntEn;
//} strTimerConfigType_t;
//
///*- CONSTANTS --------------------------------------------*/
//extern const strTimerConfigType_t astrTimerConfigParameters[TM_GROUPS_NO];
//
//
///*- FUNCTION PROTOTYPES ----------------------------------*/
//
///*************************************************************************************************
//* Parameters (in) : None
//* Parameters (out): None
//* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
//* Description     : A function to initialize all the TM groups according to the configuration
//*************************************************************************************************/
//enuErrorStatus_t Timer_Init(void);
//
///*************************************************************************************************
//* Parameters (in) : u8_GroupId(index to the timer number), u32_TimerValueUS(the value to be written to the timer)
//* 					pfCallback(pointer to call back function to be called when interrupt is fired)
//* Parameters (out): None
//* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
//* Description     : A function to initiate a timer delay on the selected TM group
//*************************************************************************************************/
//enuErrorStatus_t Timer_Start(uint8_t u8_GroupId, uintt32_t u32_TimerValueUS, void(*pfCallback)(void));
//
///*************************************************************************************************
//* Parameters (in) : u8_GroupId(index to the timer number)
//* Parameters (out): None
//* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
//* Description     : A function to stop a timer
//*************************************************************************************************/
//enuErrorStatus_t Timer_Stop(uint8_t u8_GroupId);
//
///*************************************************************************************************
//* Parameters (in) : u8_GroupId(index to the timer number)
//* Parameters (out): None
//* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
//* Description     : A function to check periodically for the timer flag
//*************************************************************************************************/
//enuErrorStatus_t Timer_GetStatus(uint8_t u8_GroupId);


#endif /* MCAL_TIMER_TM_INT_H_ */
