/**
	\file
	\brief
		This is the starter file of FlexTimer.
		In this file the FlexTimer is configured in overflow mode.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	21/03/2019
	\todo
	    Add configuration structures.
 */



#include "FlexTimer.h"
#include "MK64F12.h"
#include "Bits.h"

gpio_pin_control_register_t FTM_Pin_config = PORT_PCR_MUX(0x4);

void FTM0_ISR()
{

}

void FlexTimer_update_channel_value(uint16_t channel_value)
{
	/**Assigns a new value for the duty cycle*/
	FTM0->CONTROLS[0].CnV = channel_value;
}

void FlexTimer_update_mod_value(uint16_t FTM_channel, float frecuency_scaler)
{
	uint32_t output_frecuency = 0;
	output_frecuency = FlexTimer_get_output_frecuency(FTM_channel);
	uint32_t mod = 0;
	mod = FlexTimer_get_mod(output_frecuency, frecuency_scaler);
	FTM0->MOD = mod;
}

uint32_t FlexTimer_get_mod(uint32_t output_frecuency, float frecuency_scaler)
{
	uint32_t mod = 0;
	mod = (uint32_t)(((CLK_FRECUENCY_DIVIDED_BY_TWO)/(FLEX_TIMER_PRESCALER1_DIRECT_VALUE*output_frecuency*frecuency_scaler))-1);
	return mod;
}

uint32_t FlexTimer_get_output_frecuency(uint16_t FTM_channel)
{
	uint32_t output_frecuency = 0;
	output_frecuency = ((CLK_FRECUENCY_DIVIDED_BY_TWO)/((FLEX_TIMER_PRESCALER1_DIRECT_VALUE)*(FTM0->MOD + 1)));
	return output_frecuency;
}

void FlexTimer_PWM_Modify_Duty_Cycle(uint8_t intensity, FTM_Channel_t channel)
{
	switch(channel)
	{
	case CH0:
		FTM0->CONTROLS[0].CnV = intensity;	//RED
		break;

	case CH1:
		FTM0->CONTROLS[1].CnV = intensity; //Green
		break;

	case CH2:
		FTM0->CONTROLS[2].CnV = intensity; //BLUE
		break;
		}

}

void FlexTimer_PWM_CA_Init()
{


	/**Clock gating for FlexTimer*/
	SIM->SCGC6 |= SIM_SCGC6_FTM0(1);
	/**When write protection is enabled (WPDIS = 0), write protected bits cannot be written.
	* When write protection is disabled (WPDIS = 1), write protected bits can be written.*/
	FTM0->MODE |= FTM_MODE_WPDIS_MASK;
	/**Enables the writing over all registers*/
	FTM0->MODE &= ~ FTM_MODE_FTMEN_MASK;
	/**Assigning a default value for modulo register*/
	FTM0->MOD = MOD_255_VALUE;
	/**Selects the Edge-Aligned PWM mode mode*/
	FTM0->CONTROLS[0].CnSC = FTM_CnSC_MSB(1) | FTM_CnSC_ELSB(1);
	/**Assign a duty cycle of 50%*/
	FTM0->CONTROLS[0].CnV = ((FTM0->MOD)/2);//Default 50% of duty cycle

	FTM0->CONTROLS[1].CnSC = FTM_CnSC_MSB(1) | FTM_CnSC_ELSB(1);
	/**Assign a duty cycle of 50%*/
	FTM0->CONTROLS[1].CnV = ((FTM0->MOD)/2);//Default 50% of duty cycle

	FTM0->CONTROLS[2].CnSC = FTM_CnSC_MSB(1) | FTM_CnSC_ELSB(1);
	/**Assign a duty cycle of 50%*/
	FTM0->CONTROLS[2].CnV = ((FTM0->MOD)/2);//Default 50% of duty cycle

	/**Configure the times*/
	FTM0->SC |= FTM_SC_CLKS(FLEX_TIMER_CLKS_1)| FTM_SC_PS(FLEX_TIMER_PS_128);

	GPIO_clock_gating(GPIO_C); //External LEDs in Port C #YOLO
	GPIO_pin_control_register(GPIO_C, bit_1, &FTM_Pin_config); //PTC1 Alt4, FTM0_CH0. RED LED
	GPIO_pin_control_register(GPIO_C, bit_2, &FTM_Pin_config); //PTC2 Alt4, FTM0_CH1. GREEN LED
	GPIO_pin_control_register(GPIO_C, bit_3, &FTM_Pin_config); //PTC3 Alt4, FTM0_CH2. BLUE LED


}
