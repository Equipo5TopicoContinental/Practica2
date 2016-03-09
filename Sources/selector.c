
/*!
 * $Source: Practica1.c $
 * $Revision: 1.0 $
 * $Author: Team 5
 * $Date: 2016/02/15 22:53:07CEST $
 */


/* Includes */
/*============================================================================*/
#include "derivative.h" /* include peripheral declarations */
#include "types.h"
#include "selector.h"
#define BitIoLdd1_MODULE_BASE_ADDRESS FPTB_BASE_PTR /*!< Name of macro used as the base address */
#define BitIoLdd1_PORTCONTROL_BASE_ADDRESS PORTB_BASE_PTR /*!< Name of macro used as the base address */
#define BitIoLdd1_PORT_MASKA 0x0100U    /*!< Mask of the allocated pin from the port */
#define BitIoLdd1_PORT_MASKB 0x0200U    /*!< Mask of the allocated pin from the port */
#define GPIO_PDD_GetPortDataInput(PeripheralBase) ( \
    (uint32_t)GPIO_PDIR_REG(PeripheralBase) \
  )


/* Constants and types  */
/*============================================================================*/
/* Definition of implementation constants */


/* Variables */
/*============================================================================*/




/* Exported functions */
/*============================================================================*/
void p_Init_Selector(void);
SELECTOR_STATE p_Get_Selector_State();

/* Private functions prototypes */
/*============================================================================*/
T_BOOL p_Read_A();
T_BOOL p_Read_B();

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : p_Read_A
 *  Description          : Function to read the input A
 *  Parameters           : void
 *  Return               : T_BOOL
 *  Critical/explanation : [No]
 **************************************************************/
T_BOOL p_Read_A(void)
{
	uint32_t PortData;                   
	/* Port data masked according to the bit used */
	PortData = GPIO_PDD_GetPortDataInput(BitIoLdd1_MODULE_BASE_ADDRESS) & BitIoLdd1_PORT_MASKA;
	return (PortData != 0U) ? (T_BOOL)1 :  (T_BOOL)0;
}

/**************************************************************
 *  Name                 : p_Read_B
 *  Description          : Function to read the input B
 *  Parameters           : void
 *  Return               : T_BOOL
 *  Critical/explanation : [No]
 **************************************************************/
T_BOOL p_Read_B(void)
{
	uint32_t PortData;                   
	/* Port data masked according to the bit used */
	PortData = GPIO_PDD_GetPortDataInput(BitIoLdd1_MODULE_BASE_ADDRESS) & BitIoLdd1_PORT_MASKB;
	return (PortData != 0U) ? (T_BOOL)1 :  (T_BOOL)0;
}





/* Exported functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : p_Init
 *  Description          : Function to initialize the variables
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_Init_Selector(void)
{
	/* Configure pin as input */
	/* GPIOB_PDDR: PDD&=~0x0100 */ //Port 8
	/* GPIOB_PDDR: PDD&=~0x0200 */ //Port 9
	  GPIOB_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x0300));
	  /* Initialization of Port Control register */
	  /* PORTB_PCR8: ISF=0,MUX=1 */
	  PORTB_PCR8 = (uint32_t)((PORTB_PCR8 & (uint32_t)~(uint32_t)(
					PORT_PCR_ISF_MASK |
					PORT_PCR_MUX(0x06)
				   )) | (uint32_t)(
					PORT_PCR_MUX(0x01)
				   ));
	  PORTB_PCR9 = (uint32_t)((PORTB_PCR9 & (uint32_t)~(uint32_t)(
					 PORT_PCR_ISF_MASK |
					 PORT_PCR_MUX(0x06)
					)) | (uint32_t)(
					 PORT_PCR_MUX(0x01)
					));
}



SELECTOR_STATE p_Get_Selector_State(){
	T_BOOL a,b;
	a = p_Read_A(); //LSB
	b = p_Read_B(); //MSB
	T_UBYTE val = a + (b <<1); 	
	return (SELECTOR_STATE)val;
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */

