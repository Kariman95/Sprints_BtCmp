#ifndef MCAL_32_ADC_ADC_INTERFACE_H_
#define MCAL_32_ADC_ADC_INTERFACE_H_

#include"../../LIB/Data_types.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_registers.h"

typedef enum {
       ADC_PRESCALLER_2 =0,
	   ADC_PRESCALLER_4,
	   ADC_PRESCALLER_8,
	   ADC_PRESCALLER_16,
	   ADC_PRESCALLER_32,
	   ADC_PRESCALLER_64,
	   ADC_PRESCALLER_128,
}enuPrescaller_t;

typedef enum{
	ADC_AREFF=0,
	ADC_AVCC,
	ADC_INTERNAL=3,
}enuVreff_t;

#define Free_Running_mode				0
#define Analog_Comparator				1
#define External_Interrupt_Request_0	2
#define Timer_Counter0_Compare_Match	3
#define Timer_Counter0_Overflow			4
#define Timer_Counter1_Compare_Match_B  5
#define Timer_Counter1_Overflow			6
#define Timer_Counter1_Capture_Event	7

void ADC_init(enuPrescaller_t enuPrescaller, enuVreff_t enuVreff);
uintt16_t ADC_Read(uint8_t u8Channel);

#endif /* MCAL_32_ADC_ADC_INTERFACE_H_ */
