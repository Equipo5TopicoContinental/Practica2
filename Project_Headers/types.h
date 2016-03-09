/*!
 * $Source: Practica1.h $
 * $Revision: 1.0 $
 * $Author: Fill with team number $
 * $Date: 2015/08/26 22:53:15CEST $
 */

#ifndef TYPES_H
#define TYPES_H

/* Includes */
#define RED_LED 0x00040000
#define GREEN_LED 0x00080000
#define BLUE_LED 0x00000002
#define FALSE 0
#define TRUE 1	



/* Constants and types */
/*============================================================================*/
typedef unsigned char T_UBYTE ;
typedef unsigned int T_UWORD ;
typedef unsigned char T_BOOL ;
typedef signed int T_WORD;

typedef enum {
	LIGHTS_OFF=0,
	HALF_LIGHTS,
	LIGHTS_ON	
} LIGHT_STATE;

typedef enum{
	OFF=0,
	PARKLAMPS,
	HEADLAMPS,
	AUTO
} SELECTOR_STATE;



#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
