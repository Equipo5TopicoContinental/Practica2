/*
 * lights.c
 *
 *  Created on: Mar 8, 2016
 *      Author: Adrian
 */
#include "lights.h"
#include "selector.h"

void delay_100ms(void);

SELECTOR_STATE selector_state;
LIGHT_STATE light_state, prev_state;

void loop(void){
	
	for(;;){
		selector_state = p_Get_Selector_State();
		switch(selector_state){
		case OFF:
			light_state = LIGHTS_OFF;
			p_Set_Lights_State(light_state);
			break;
		case PARKLAMPS:
			light_state = HALF_LIGHTS;
			p_Set_Lights_State(light_state);
			break;
		case HEADLAMPS:
			light_state = LIGHTS_ON;
			p_Set_Lights_State(light_state);
			break;
		case AUTO:
			auto_lights();
			break;
		}
		delay_100ms();
	}
}

void auto_lights(){
	T_UWORD light_sensor = 100;
	light_sensor = p_Get_Light_Sensor();
	if(light_sensor < 40){
		if(light_state == LIGHTS_OFF){
			light_state = LIGHTS_ON;
			p_Set_Lights_State(light_state);
		}
	}
	if(light_sensor > 60){
		if(light_state == LIGHTS_ON){
			light_state = HALF_LIGHTS;
			p_Set_Lights_State(light_state);
		}
	}
	if(light_sensor > 80){
		if(light_state == HALF_LIGHTS){
			light_state = LIGHTS_OFF;
			p_Set_Lights_State(light_state);
		}
	}
}

void delay_100ms(void){
	int cnt;
	for(cnt=0;cnt < 100000; ++cnt);
}
