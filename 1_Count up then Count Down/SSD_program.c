/****************************************************************/
/****************************************************************/
/**************   Author: Youssef  Ahmed	*********************/
/**************   Layer: HAL				*********************/
/**************   SWC: SSD					*********************/
/**************   Version: 1.00				*********************/
/**************   Date:1/11/2023				*********************/

#include "SSD_interface.h"
#include "SSD_private.h"
#include "DIO_interface.h"



u8 SSD_Num[10]=SSD_NUMBERS;

void SSD_voidInit       	 ( SSD_Type SSD_Configuration )
{
	DIO_enumSetPortDirection(SSD_Configuration.Port,DIO_PORT_HIGH);
}

void SSD_voidEnable          ( SSD_Type SSD_Configuration )
{
	if(SSD_Configuration.Com_Type == COMMON_CATHOD)
	{
		DIO_enumSetPinDirection(SSD_Configuration.Enable_Port,SSD_Configuration.Enable_Pin,DIO_PIN_OUTPUT);
		DIO_enumSetPinValue(SSD_Configuration.Enable_Port,SSD_Configuration.Enable_Pin,DIO_PIN_LOW);
	}
	else if(SSD_Configuration.Com_Type == COMMON_ANODE)
	{
		DIO_enumSetPinDirection(SSD_Configuration.Enable_Port,SSD_Configuration.Enable_Pin,DIO_PIN_OUTPUT);
			DIO_enumSetPinValue(SSD_Configuration.Enable_Port,SSD_Configuration.Enable_Pin,DIO_PIN_HIGH);
	}

}

void SSD_voidDisable         ( SSD_Type SSD_Configuration )
{
	 if(SSD_Configuration.Com_Type == COMMON_CATHOD)
		{
			DIO_enumSetPinDirection(SSD_Configuration.Enable_Port,SSD_Configuration.Enable_Pin,DIO_PIN_OUTPUT);
				DIO_enumSetPinValue(SSD_Configuration.Enable_Port,SSD_Configuration.Enable_Pin,DIO_PIN_HIGH);
		}
	 else if(SSD_Configuration.Com_Type == COMMON_ANODE)
	 	{
	 		DIO_enumSetPinDirection(SSD_Configuration.Enable_Port,SSD_Configuration.Enable_Pin,DIO_PIN_OUTPUT);
	 			DIO_enumSetPinValue(SSD_Configuration.Enable_Port,SSD_Configuration.Enable_Pin,DIO_PIN_LOW);
	 	}
}

void SSD_voidSendNumber      ( SSD_Type SSD_Configuration ,u8 Copy_u8value)
{
	if(SSD_Configuration.Com_Type==COMMON_CATHOD)
	{
		DIO_enumSetPortValue(SSD_Configuration.Port,SSD_Num[Copy_u8value]);

	}
	else if(SSD_Configuration.Com_Type==COMMON_ANODE)
	{

		DIO_enumSetPortValue(SSD_Configuration.Port,~SSD_Num[Copy_u8value]);
	}
}
void SSD_voidSendSpecificNumber      ( SSD_Type SSD_Configuration ,u8 Copy_u8value)
{
	if(SSD_Configuration.Com_Type==COMMON_CATHOD)
	{
		DIO_enumSetPortValue(SSD_Configuration.Port,Copy_u8value);

	}
	else if(SSD_Configuration.Com_Type==COMMON_ANODE)
	{

		DIO_enumSetPortValue(SSD_Configuration.Port,~Copy_u8value);
	}
}
