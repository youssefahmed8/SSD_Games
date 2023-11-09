/****************************************************************/
/****************************************************************/
/**************   Author: Youssef  Ahmed	*********************/
/**************   Layer: HAL				*********************/
/**************   SWC: SW					*********************/
/**************   Version: 1.00				*********************/
/**************   Date: 8/11/23				*********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SW_interfac.h"



void SW_voidInit(SW_type SW_Config)
{
	DIO_enumSetPinDirection(SW_Config.SW_Port,SW_Config.SW_Pin,DIO_PIN_INPUT);
	if(SW_Config.SW_Type==PULLUP)
	{
	DIO_enumSetPinValue(SW_Config.SW_Port,SW_Config.SW_Pin,DIO_PIN_HIGH);
	}
}
