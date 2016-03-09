/*
 * light_sensor.c
 *
 *  Created on: Mar 8, 2016
 *      Author: Adrian
 */
#include "types.h"
#include "derivative.h"
#include "light_sensor.h"

#define ADC_PIN 8
volatile T_WORD AD1_OutV;    

/* Exported functions prototypes */
/*============================================================================*/
void p_Init_Light_Sensor(void);
T_UWORD p_Get_Light_Sensor(void);

/* Exported functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : p_Init_Light_Sensor
 *  Description          : Function to initialize the variables
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_Init_Light_Sensor(void){
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK; 								// HABILITA RELOJ PARA ADC
	ADC0_CFG1 |= (ADC_CFG1_MODE( 3 )) | (ADC_CFG1_ADIV(3)); 		// RESOLUCION DEL ADC
	ADC0_SC1A = ADC_SC1_ADCH(31); 	
}

T_UWORD p_Get_Light_Sensor(void)
{
	T_UBYTE port = ADC_PIN;
	ADC0_SC1A = port & ADC_SC1_ADCH_MASK; 								// ACTIVA LA CONVERSION MEDIANTE EL CANAL
	while( ADC0_SC2 & ADC_SC2_ADACT_MASK );
	while( !(ADC0_SC1A & ADC_SC1_COCO_MASK));
	T_UWORD res  =(T_UWORD)ADC0_RA; 
	res = (65000.0 - res)/60000.0 * 100.0;
	return res;
}



