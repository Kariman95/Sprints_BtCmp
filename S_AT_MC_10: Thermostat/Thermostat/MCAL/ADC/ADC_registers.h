/*
 * ADC_registers.h
 *
 *  Created on: Jul 24, 2021
 *      Author: Kariman
 */

#ifndef MCAL_ADC_ADC_REGISTERS_H_
#define MCAL_ADC_ADC_REGISTERS_H_

#include "../../LIB/Data_types.h"

/*******************************************************************************
 *                           ADC Registers                                     *
********************************************************************************/
#define ADMUX_R   (*(volatile uint8_t *) 0x27)
#define ADLAR_B   5
#define REFS0_B   6
#define REFS1_B   7


#define ADCSRA_R  (*(volatile uint8_t*) 0x26)
#define ADEN_B    7
#define ADSC_B    6
#define ADATE_B   5
#define ADIF_B    4
#define ADIE_B    3
#define ADPS2_B   2
#define ADPS1_B   1
#define ADPS0_B   0

#define ADCH_R    (*(volatile uint8_t*) 0x25)
#define ADCL_R    (*(volatile uint8_t*) 0x24)
#define ADC_R	  (*(volatile uintt16_t*)0x24)


#endif /* MCAL_ADC_ADC_REGISTERS_H_ */
