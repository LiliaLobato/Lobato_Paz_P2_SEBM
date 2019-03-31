/*
 * PH.c
 *
 *  Created on: 31/03/2019
 *      Author: Lilia Lobato
 */

#include <stdint.h>
#include <Potenciometro.h>
#include <RGB_external.h>

//Rango 1
#define PH1 0
#define PH6 2047
//Rango 2
#define PH7 2048
#define PH10 3217
//Rango 3
#define PH11 3218
#define PH14 4095

//typedef enum {RGB_RED,RGB_GREEN,RGB_BLUE} rgb_color;

//FlexTimer_PWM_Modify_Duty_Cycle(uint8_t intensity, FTM_Channel_t channel)

void PH_rgb_change(void) {
	uint16_t potvalor = POTENCIOMETRO_getValorPot();
	uint8_t potR = 0;
	uint8_t potG = 0;
	uint8_t potB = 0;
	if (PH14 >= potvalor && PH11 <= potvalor) {
		//Escalamiento x1000 para realizar regla de 3
		float diferencia = (PH14 - PH11);
		float divisor = (potvalor - PH11);
		float dividendo = (uint32_t) (1000) * (divisor / diferencia);
		float regla3 = (uint32_t) dividendo * 255;
		float potPH = (uint32_t) regla3 / 1000;
		//Paso de valores para la regla de 3
		potR = (uint8_t) (potPH);
		potG = 0;
		potB = 255;
		RGB_external_change_color(potR, RGB_RED);
		RGB_external_change_color(potG, RGB_GREEN);
		RGB_external_change_color(potB, RGB_BLUE);
	} else if (PH10 >= potvalor && PH7 <= potvalor) {
		//Escalamiento x1000 para realizar regla de 3
		float diferencia = (PH10 - PH7);
		float divisor = (potvalor - PH7);
		float dividendo = (uint32_t) (1000) * (divisor / diferencia);
		float regla3 = (uint32_t) dividendo * 255;
		float potPH = (uint32_t) regla3 / 1000;
		//Paso de valores para la regla de 3
		potR = 0;
		potG = (uint8_t) (255 - potPH);
		potB = (uint8_t) (potPH);
		RGB_external_change_color(potR, RGB_RED);
		RGB_external_change_color(potG, RGB_GREEN);
		RGB_external_change_color(potB, RGB_BLUE);
	} else if (PH6 >= potvalor && PH1 <= potvalor) {
		//Escalamiento x1000 para realizar regla de 3
		float diferencia = (PH6 - PH1);
		float divisor = (potvalor - PH1);
		float dividendo = (uint32_t) (1000) * (divisor / diferencia);
		float regla3 = (uint32_t) dividendo * 255;
		float potPH = (uint32_t) regla3 / 1000;
		//Paso de valores para la regla de 3
		potR = (uint8_t) (255 - potPH);
		potG = (uint8_t) (potPH);
		potB = 0;
		RGB_external_change_color(potR, RGB_RED);
		RGB_external_change_color(potG, RGB_GREEN);
		RGB_external_change_color(potB, RGB_BLUE);
	}
}
