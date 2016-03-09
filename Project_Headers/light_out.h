/*
 * light_out.h
 *
 *  Created on: Mar 7, 2016
 *      Author: Adrian
 */

#ifndef LIGHT_OUT_H_
#define LIGHT_OUT_H_
#include "types.h"
#include "derivative.h"

/* Exported functions prototypes */
/*============================================================================*/
extern void p_Init_Light_Out(void);
extern void p_Set_Lights_State(LIGHT_STATE state);
void p_Set_Park_Lamps(T_BOOL value);
void p_Set_Head_Lamps(T_BOOL value);


#endif /* LIGHT_OUT_H_ */
