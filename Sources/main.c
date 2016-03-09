/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "types.h"
#include "selector.h"
#include "light_out.h"
#include "light_sensor.h"
#include "lights.h"




int main(void)
{
	p_Init_Light_Out();
	p_Init_Selector();
	p_Init_Light_Sensor();

	loop();
	
	return 0;
}


