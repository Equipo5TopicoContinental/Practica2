/*!
 * $Source: selector.h $
 * $Revision: 1.0 $
 * $Author: Team 3 $
 * $Date: 2016/03/07 22:53:15CEST $
 */

#ifndef SELECTOR_H
#define SELECTOR_H
#include "types.h"
#include "derivative.h"


/* Exported functions prototypes */
/*============================================================================*/
extern void p_Init_Selector(void);
extern SELECTOR_STATE p_Get_Selector_State();
T_BOOL p_Read_A();
T_BOOL p_Read_B();

#endif
