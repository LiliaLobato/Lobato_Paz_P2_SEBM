/**
	\file
	\brief
		This is the header file for the FlexTimer divice driver.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	21/03/2019
	\todo
	    Add configuration structures.
 */

#ifndef FLEXTIMER_H_
#define FLEXTIMER_H_

#include "GPIO.h"
#include "MK64F12.h"
#include "stdint.h"

typedef enum {
	INPUT_CAPTURE,
	OUTPUT_COMPARE,
	EDGE_ALIGNED_PWM,
	CENTER_ALIGNED_PWM,
	COMBINE_PWM,
	DUAL_EDGE_CAPTURE_MODE
} ft_mode;

typedef enum {
	TOOGLE, CLEAR, SET
} input_capture_els;


#define FLEX_TIMER_CLKS_0  (0U)
#define FLEX_TIMER_CLKS_1  (1U)
#define FLEX_TIMER_CLKS_2  (2U)
#define FLEX_TIMER_CLKS_3  (3U)


#define FLEX_TIMER_PS_1    (0U)
#define FLEX_TIMER_PS_2    (1U)
#define FLEX_TIMER_PS_4    (2U)
#define FLEX_TIMER_PS_8    (3U)
#define FLEX_TIMER_PS_16    (4U)
#define FLEX_TIMER_PS_32    (5U)
#define FLEX_TIMER_PS_64    (6U)
#define FLEX_TIMER_PS_128    (7U)
#define FLEX_TIMER_PRESCALER1_DIRECT_VALUE (1U)


#define  FLEX_TIMER_DMA   0x01
#define  FLEX_TIMER_ELSA  0x04
#define  FLEX_TIMER_ELSB  0x08
#define  FLEX_TIMER_MSA   0x10
#define  FLEX_TIMER_MSB   0x20
#define  FLEX_TIMER_CHIE  0x40
#define  FLEX_TIMER_CHF   0x80

#define CLK_FRECUENCY_DIVIDED_BY_TWO (10500000U) //10.5 MHz
#define MOD_255_VALUE 0xFF

typedef enum
{
	CH0, CH1, CH2
}FTM_Channel_t;


void FlexTimer_PWM_Modify_Duty_Cycle(uint8_t intensity, FTM_Channel_t channel);

void FlexTimer_update_channel_value(uint16_t channel_value);
void FlexTimer_update_mod_value(uint16_t channel_value, float frecuency_scaler);
uint32_t FlexTimer_get_mod(uint32_t output_frecuency, float frecuency_scaler);
uint32_t FlexTimer_get_output_frecuency(uint16_t channel_value);

void FlexTimer_PWM_CA_Init();
void FlexTimer_Init();
void Compare_init(uint32_t mod, uint32_t cnv, input_capture_els els, uint8_t Flex_Timer_clk_N, uint8_t Flex_Timer_ps_N);
void PWM_init_p(ft_mode mode);
void Capture_init(ft_mode mode);


#endif /* FLEXTIMER_H_ */
