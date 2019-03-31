/*
 * Potenciometro.h
 *
 *  Created on: 30/03/2019
 *      Author: Lilia Lobato
 */

#ifndef POTENCIOMETRO_H_
#define POTENCIOMETRO_H_

//Retorna el valor promedio de 10 muestras
void POTENCIOMETRO_result(void);

//Retorno de valores dependiendo de la escala
uint16_t POTENCIOMETRO_getValorPot(); //Valor directo del pot
float POTENCIOMETRO_0to33(); //Valor en escala 0 a 3.3

//Inicialización del reloj en 10ms
void POTENCIOMETRO_PIT_init(void);

#endif /* POTENCIOMETRO_H_ */
