///*
// * TM_prog.c
// *
// *  Created on: Jul 10, 2021
// *      Author: Kariman
// */
//
///*- INCLUDES
//----------------------------------------------*/
//#include "../../LIB/BIT_math.h"
//#include "../../LIB/Data_types.h"
//#include "TM_Int.h"
//#include "TM_Cfg.h"
//#include "TM_registers.h"
//
//static uintt32_t u32_OverflowNum = 0;
//static uint8_t u8_TM0Preload = 0;
//static void(*pf_OVflowCallback)(void) = NULL_PTR;
//
//static enuErrorStatus_t TM0_delayUs(uint8_t u8_GroupId, uintt32_t u32_Time);
//
///*- APIs IMPLEMENTATION-----------------------------------*/
//
///*************************************************************************************************
//* Parameters (in) : None
//* Parameters (out): None
//* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
//* Description     : A function to initialize all the TM groups according to the configuration
//*************************************************************************************************/
//enuErrorStatus_t Timer_Init(void)
//{
//	uint8_t u8_i;
//
//	for(u8_i=0; u8_i < TM_GROUPS_NO; u8_i++)
//	{
//		/*--select the timer--*/
//		switch(astrTimerConfigParameters[u8_i].enuTimerModule)
//		{
//		case TIMER0:
//		{
//			/*- Mode selection -*/
//			switch(astrTimerConfigParameters[u8_i].enuTimerMode)
//			{
//			case NORMAL:
//				CLR_BIT(TCCR0_R, WGM00_BIT);
//				CLR_BIT(TCCR0_R, WGM01_BIT);
//				/*--Normal port operation, OC0 disconnected--*/
//				CLR_BIT(TCCR0_R, COM00_BIT);
//				CLR_BIT(TCCR0_R, COM01_BIT);
//
//				/*- Selecting whether to enable or disable timer module interrupts -*/
//				if(astrTimerConfigParameters[u8_i].enuTimerIntEn == TIMER_INT_DIS)
//				{
//					CLR_BIT(TIMSK_R, TOIE0_BIT);
//				}//end if
//				else if(astrTimerConfigParameters[u8_i].enuTimerIntEn == TIMER_INT_EN)
//				{
//					SET_BIT(SREG_R, SREG_I_BIT);
//					SET_BIT(TIMSK_R, TOIE0_BIT);
//				}//end else
//				break;
//			case CTC:
//				CLR_BIT(TCCR0_R, WGM00_BIT);
//				SET_BIT(TCCR0_R, WGM01_BIT);
//
//		        /*- Toggle OC0 on compare match -*/
//		        CLR_BIT(TCCR0_R, COM01_BIT);
//		        SET_BIT(TCCR0_R, COM00_BIT);
//
//				/*- Selecting whether to enable or disable timer module interrupts -*/
//				if(astrTimerConfigParameters[u8_i].enuTimerIntEn == TIMER_INT_DIS)
//				{
//					CLR_BIT(TIMSK_R, OCIE0_BIT);
//				}//end if
//				else if(astrTimerConfigParameters[u8_i].enuTimerIntEn == TIMER_INT_EN)
//				{
//					SET_BIT(SREG_R, SREG_I_BIT);
//					SET_BIT(TIMSK_R, OCIE0_BIT);
//				}//end else
//				break;
//			case PC_PWM:
//				SET_BIT(TCCR0_R, WGM00_BIT);
//				CLR_BIT(TCCR0_R, WGM01_BIT);
//
//				break;
//			case FAST_PWM:
//				SET_BIT(TCCR0_R, WGM00_BIT);
//				SET_BIT(TCCR0_R, WGM01_BIT);
//				break;
//			}//end switch for mode
//
///*- Step2 : prescaler selection ------------------------------------------------------------*/
//			switch(astrTimerConfigParameters[u8_i].enuTimerClock)
//			{
//			case NO_CLOCK:
//				CLR_BIT(TCCR0_R, CS00_BIT);
//				CLR_BIT(TCCR0_R, CS01_BIT);
//				CLR_BIT(TCCR0_R, CS02_BIT);
//				break;
//			case NO_PRESCALER:
//				SET_BIT(TCCR0_R, CS00_BIT);
//				CLR_BIT(TCCR0_R, CS01_BIT);
//				CLR_BIT(TCCR0_R, CS02_BIT);
//				break;
//			case PRESCALER_8:
//				CLR_BIT(TCCR0_R, CS00_BIT);
//				SET_BIT(TCCR0_R, CS01_BIT);
//				CLR_BIT(TCCR0_R, CS02_BIT);
//				break;
//			case PRESCALER_64:
//				SET_BIT(TCCR0_R, CS00_BIT);
//				SET_BIT(TCCR0_R, CS01_BIT);
//				CLR_BIT(TCCR0_R, CS02_BIT);
//				break;
//			case PRESCALER_256:
//				CLR_BIT(TCCR0_R, CS00_BIT);
//				CLR_BIT(TCCR0_R, CS01_BIT);
//				SET_BIT(TCCR0_R, CS02_BIT);
//				break;
//			case PRESCALER_1024:
//				SET_BIT(TCCR0_R, CS00_BIT);
//				CLR_BIT(TCCR0_R, CS01_BIT);
//				SET_BIT(TCCR0_R, CS02_BIT);
//				break;
//			case EXTERNAL_CLOCK_FALL_EDGE:
//				CLR_BIT(TCCR0_R, CS00_BIT);
//				SET_BIT(TCCR0_R, CS01_BIT);
//				SET_BIT(TCCR0_R, CS02_BIT);
//				break;
//			case EXTERNAL_CLOCK_RISE_EDGE:
//				SET_BIT(TCCR0_R, CS00_BIT);
//				SET_BIT(TCCR0_R, CS01_BIT);
//				SET_BIT(TCCR0_R, CS02_BIT);
//				break;
//			}//end switch for prescaler
//			break;
//		}//end case of Timer0
//		case TIMER1:
//		{
//			break;
//		}//end case of Timer1
//		case TIMER2:
//		{
//			break;
//		}//end case of Timer2
//		}//end switch for module
//	}//end for
//
//	return E_OK;
//}//end Timer_Init
//
///*************************************************************************************************
//* Parameters (in) : u8_GroupId(index to the timer number), u32_TimerValueUS(the value to be written to the timer)
//* 					pfCallback(pointer to call back function to be called when interrupt is fired)
//* Parameters (out): None
//* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
//* Description     : A function to initiate a timer delay on the selected TM group
//*************************************************************************************************/
//enuErrorStatus_t Timer_Start(uint8_t u8_GroupId, uintt32_t u32_TimerValueUS, void(*pfCallback)(void))
//{
////	uintt32_t u32_TickTime;
//////	uintt32_t u32_OverflowTime;
////	uintt32_t u32_OverflowRem;
////	uintt32_t u32_OverflowRemCounts;
//
//	if(astrTimerConfigParameters[u8_GroupId].enuTimerModule == TIMER0)
//	{
//		if(astrTimerConfigParameters[u8_GroupId].enuTimerMode == NORMAL)
//		{
//
//			//setting call back function
//			pf_OVflowCallback = pfCallback;
//
//			//initializing value of tcnt0
//			TCNT0_R = 0;
//
//			TM0_delayUs(u8_GroupId, u32_TimerValueUS);
//
//		}//end if for NORMAL mode
//		else if(astrTimerConfigParameters[u8_GroupId].enuTimerMode == CTC)
//		{
//
//		}//end else if for CTC mode
//		//start to count by setting clk
//	}//end if for Timer0
//	return E_OK;
//}//end Timer_Start
//
//
//static enuErrorStatus_t TM0_delayUs(uint8_t u8_GroupId, uintt32_t u32_Time)
//{
//	uintt32_t TickTime = astrTimerConfigParameters[u8_GroupId].enuTimerClock / F_CPU;
//	uintt32_t numbOfTick = u32_Time / TickTime;
//	u32_OverflowNum = numbOfTick / 256;
//
////	uintt32_t TickTime = (astrTimerConfigParameters[u8_GroupId].enuTimerClock * 1000000) / F_CPU ;
////	uintt32_t OverflowTime =  TickTime  * 256 ;
////	uintt32_t DesiredTime = Time;
////
////	u32_OverflowNum = DesiredTime / OverflowTime;
////	uintt32_t OverflowRemTime = DesiredTime % OverflowTime;
////	uintt32_t OverflowRemCounts = ((float)OverflowRemTime/OverflowTime)* 256;
////
////	TCNT0_R = 0;
////	if(OverflowRemTime>0)
////	{
////		u8_TM0Preload = 256 - OverflowRemCounts;
////		TCNT0_R = u8_TM0Preload;
////		u32_OverflowNum++;
////	}
//
//	return E_OK;
//}
//
//
///*************************************************************************************************
//* Parameters (in) : u8_GroupId(index to the timer number)
//* Parameters (out): None
//* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
//* Description     : A function to stop a timer
//*************************************************************************************************/
//enuErrorStatus_t Timer_Stop(uint8_t u8_GroupId)
//{
////	TCCR0_R &= 0xf8;//0b1111 1000
//	CLR_BIT(TCCR0_R, CS00_BIT);
//	CLR_BIT(TCCR0_R, CS01_BIT);
//	CLR_BIT(TCCR0_R, CS02_BIT);
//	return E_OK;
//}//end Timer_Stop
//
///*************************************************************************************************
//* Parameters (in) : u8_GroupId(index to the timer number)
//* Parameters (out): None
//* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
//* Description     : A function to check periodically for the timer flag
//*************************************************************************************************/
//enuErrorStatus_t Timer_GetStatus(uint8_t u8_GroupId)
//{
//	if(astrTimerConfigParameters[u8_GroupId].enuTimerModule == TIMER0)
//	{
//		switch(astrTimerConfigParameters[u8_GroupId].enuTimerMode)
//		{
//		case NORMAL:
//			/* Checking timer 0 overflow flag */
//			if(GET_BIT(TIFR_R, TOV0_BIT))
//			{
//				/* Clear timer0 OVF flag */
//				SET_BIT(TIFR_R, TOV0_BIT);
//				/* Stopping the timer by loading a No Clock condition */
//				Timer_Stop(u8_GroupId);
//
//				/* Call the call back function */
//				pf_OVflowCallback();
//			}
//			else;
//			break;
//		case CTC:
//			break;
//		break;
//		}//end switch
//	}//end if for timer0
//	else;
//
//	return E_OK;
//}//end Timer_GetStatus
//
///*************************************************************************************************
//* Parameters (in) : None
//* Parameters (out): None
//* Return Value    : void
//* Description     : ISR to handle OVFlow Interrupt for Timer0
//*************************************************************************************************/
//void __vector_11 (void) __attribute__((signal));
//void __vector_11 (void)
//{
//	static uintt32_t u32_Counter = 0;
//	u32_Counter++;
//	if(u32_Counter ==  u32_OverflowNum)
//	{
//		if(pf_OVflowCallback != NULL_PTR)
//		{
//			pf_OVflowCallback();
//			u32_Counter = 0;
//			TCNT0_R = u8_TM0Preload;
//		}//end if
//		else;
//	}//end if
//	else;
//}//end ISR
