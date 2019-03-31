/*
 * Potenciometro.c
 *
 *  Created on: 30/03/2019
 *      Author: Lilia Lobato
 */

#include "SPI.h"
#include "GPIO.h"
#include "Bits.h"
#include "LCD_nokia.h"
#include "LCD_nokia_images.h"
#include "stdint.h"
#include "PIT.h"
#include "Delay.h"
#include "Pantalla.h"
#include "ADC.h"

#define ADC_0 0
#define SYSTEM_CLOCK (21000000U)
#define DELAYPOT (0.01F)
#define MUESTRAMAX 10

uint8_t muestraNum = FALSE;
uint16_t valorPot[9] = { FALSE };
uint16_t pot = FALSE;

//PTE24 tarjeta, ADC0SE17 mapeado en 10001
void POTENCIOMETRO_result() {
	uint16_t muestraPromedio=FALSE;
	if (TRUE == PIT_get0_interrupt_flag_status()) {
		if (MUESTRAMAX == muestraNum) {
			for(uint8_t i=0;i<10;i++){
				muestraPromedio=muestraPromedio+valorPot[i];
			}
			pot = (uint16_t)(muestraPromedio/10);
			muestraNum=FALSE;
		} else {
			valorPot[muestraNum] = ADC_result(ADC_0);
			muestraNum++;
		}
	}
	PIT_clear0_interrupt_flag();
}

uint16_t POTENCIOMETRO_getValorPot(){
	return pot;
}

float POTENCIOMETRO_0to33(){
	return pot*3.3/4095;
}

void POTENCIOMETRO_PIT_init() {
	PIT_clock_gating();
	PIT_enable();
	NVIC_set_basepri_threshold(PRIORITY_12);
	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ, PRIORITY_3);
	NVIC_global_enable_interrupts;
	PIT_delay(PIT_0, SYSTEM_CLOCK, DELAYPOT);
	PIT_enable_interrupt_1(PIT_0);
}
