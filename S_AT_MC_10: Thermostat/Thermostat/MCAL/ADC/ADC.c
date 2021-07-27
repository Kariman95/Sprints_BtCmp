#include "ADC.h"
#include "ADC.h"

void ADC_init(enuPrescaller_t enuPrescaller, enuVreff_t enuVreff)
{
	//ADC ENABLE
	SET_BIT(ADCSRA_R, ADEN_B);
	//ADC INTERRUPT ENABLE
	CLR_BIT(ADCSRA_R, ADIE_B);
	//ADC
	CLR_BIT(ADMUX_R, ADLAR_B);
	////////////////////
	switch(enuPrescaller)
	{
	case ADC_PRESCALLER_2:	SET_BIT(ADCSRA_R, ADPS0_B);   CLR_BIT(ADCSRA_R, ADPS1_B);  CLR_BIT(ADCSRA_R, ADPS2_B);break;
	case ADC_PRESCALLER_4:	CLR_BIT(ADCSRA_R, ADPS0_B);   SET_BIT(ADCSRA_R, ADPS1_B);  CLR_BIT(ADCSRA_R, ADPS2_B);break;
	case ADC_PRESCALLER_8:  SET_BIT(ADCSRA_R, ADPS0_B);   SET_BIT(ADCSRA_R, ADPS1_B);  CLR_BIT(ADCSRA_R, ADPS2_B);break;
	case ADC_PRESCALLER_16: CLR_BIT(ADCSRA_R, ADPS0_B);   CLR_BIT(ADCSRA_R, ADPS1_B);  SET_BIT(ADCSRA_R, ADPS2_B);break;
	case ADC_PRESCALLER_32: SET_BIT(ADCSRA_R, ADPS0_B);   CLR_BIT(ADCSRA_R, ADPS1_B);  SET_BIT(ADCSRA_R, ADPS2_B);break;
	case ADC_PRESCALLER_64: CLR_BIT(ADCSRA_R, ADPS0_B);   SET_BIT(ADCSRA_R, ADPS1_B);  SET_BIT(ADCSRA_R, ADPS2_B);break;
	case ADC_PRESCALLER_128:SET_BIT(ADCSRA_R, ADPS0_B);   SET_BIT(ADCSRA_R, ADPS1_B);  SET_BIT(ADCSRA_R, ADPS2_B);break;
	}
	//ADC SELECT VREF
	switch(enuVreff)
	{
	case ADC_AREFF:      CLR_BIT(ADMUX_R, REFS0_B);        CLR_BIT(ADMUX_R, REFS1_B);break;
	case ADC_AVCC:       CLR_BIT(ADMUX_R, REFS1_B);        SET_BIT(ADMUX_R, REFS0_B);break;
	case ADC_INTERNAL:   SET_BIT(ADMUX_R, REFS0_B);        SET_BIT(ADMUX_R, REFS1_B);break;
	}
}
uintt16_t  ADC_Read(uint8_t u8Channel)
{
	ADMUX_R &=0xE0;
	u8Channel &=0x07;
	ADMUX_R |= u8Channel;

	//ADC start single conversion
	SET_BIT(ADCSRA_R, ADSC_B);

	//ADC wait for conversion
	while(!(ADCSRA_R & (1<<ADIF_B)));
	//ADC CLEAR FLAG
	SET_BIT(ADCSRA_R, ADIF_B);

	return ADC_R;
}
