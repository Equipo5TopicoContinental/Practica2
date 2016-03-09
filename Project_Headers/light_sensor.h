/*
 * light_sensor.h
 *
 *  Created on: Mar 8, 2016
 *      Author: Adrian
 */

#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_
#include "types.h"
#include "derivative.h"
#define ADC_PIN 8
/* Exported functions prototypes */
/*============================================================================*/
extern void p_Init_Light_Sensor(void);
extern T_UWORD p_Get_Light_Sersor(void);

#endif /* LIGHT_SENSOR_H_ */
