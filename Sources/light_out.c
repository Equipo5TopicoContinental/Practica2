/*
 * light_out.c
 *
 *  Created on: Mar 7, 2016
 *      Author: Adrian
 */
#include "derivative.h" /* include peripheral declarations */
#include "types.h"
#include "light_out.h"

/* Variables */
/*============================================================================*/
static T_BOOL r_Park_Lamps_State;
static T_BOOL r_Head_Lamps_State;


/* Exported functions prototypes */
/*============================================================================*/
void p_Init_Light_Out(void);
void p_Set_Park_Lamps(T_BOOL value);
void p_Set_Head_Lamps(T_BOOL value);
void p_Set_Lights(LIGHT_STATE state);


/* Private functions prototypes */
/*============================================================================*/
static void p_Set_Lamps(void);

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : p_Set_Lamps
 *  Description          :
 *  Parameters           :
 *  Return               :
 *  Critical/explanation :
 **************************************************************/
static void p_Set_Lamps(void)
{
	GPIOD_PSOR = BLUE_LED;
	GPIOB_PSOR = GREEN_LED | RED_LED;
	if(r_Park_Lamps_State){
		GPIOB_PCOR |= GREEN_LED;
	}
	if(r_Head_Lamps_State){
		//GPIOB_PCOR |= RED_LED;
		GPIOD_PCOR |= BLUE_LED;
	}
}

/* Exported functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : p_Init_Light_Out
 *  Description          : Function to initialize the variables
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_Init_Light_Out(void)
{
	/* Turn on clock to PortB and PortD module */
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;
	/* See "System integration module" and "System Clock Gating Control Register 5" in microcontroller user manual */
	
	/* Set the PTB18 pin multiplexer to GPIO mode */
	PORTB_PCR19 |= PORT_PCR_MUX(1); // GREEN
	PORTB_PCR18 |= PORT_PCR_MUX(1); //RED
	PORTD_PCR1 |= PORT_PCR_MUX(1) ; //BLUE
	/* See "Port control and interrupts" and "Pin Control Register n" in microcontroller user manual */
	
	/* Set the initial output state to high */
	GPIOB_PSOR = GREEN_LED;
	GPIOB_PSOR = RED_LED;
	GPIOD_PSOR = BLUE_LED;
	/* See "General-Purpose Input/Output" and "Port Set Output Register" in microcontroller user manual */
	
	/* Set the pins direction to output */
	GPIOB_PDDR |= RED_LED  | GREEN_LED;
	GPIOD_PDDR |= BLUE_LED;
}

/**************************************************************
 *  Name                 : p_Set_Park_Lamps
 *  Description          : Set value for Park Lamps
 *  Parameters           : T_BOOL
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_Set_Park_Lamps(T_BOOL value)
{
	r_Park_Lamps_State = value;
	p_Set_Lamps();
}

/**************************************************************
 *  Name                 : p_Set_Head_Lamps
 *  Description          : Set value for Head Lamps
 *  Parameters           : T_BOOL
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_Set_Head_Lamps(T_BOOL value)
{
	r_Head_Lamps_State = value;
	p_Set_Lamps();
}

void p_Set_Lights_State(LIGHT_STATE state){
	switch(state){
	case LIGHTS_OFF:
		p_Set_Head_Lamps(FALSE);
		p_Set_Park_Lamps(FALSE);
		break;
	case HALF_LIGHTS:
		p_Set_Head_Lamps(FALSE);
		p_Set_Park_Lamps(TRUE);
		break;
	case LIGHTS_ON:
		p_Set_Head_Lamps(TRUE);
		p_Set_Park_Lamps(TRUE);
		break;
	}
	
}
