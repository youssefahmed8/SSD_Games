/*
 * main.c
 *
 *  Created on: Nov 8, 2023
 *      Author: Joeo
 */


#include "STD_TYPES.h"
#include "SSD_private.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "DIO_interface.h"
#include "SW_interfac.h"
#include "util/delay.h"
#include "BIT_MATH.h"




int main()
{
	SSD_Type SSD1={COMMON_CATHOD,SSD_PORTA,SSD_PORTA,SSD_PIN7};
	SSD_Type SSD2={COMMON_CATHOD,SSD_PORTB,SSD_PORTB,SSD_PIN7};

	SSD_voidInit(SSD1);
	SSD_voidInit(SSD2);

	int i,j;

	while(1)
	{
		for(i=0;i<10;i++)
		{
			SSD_voidSendNumber(SSD1,i);
			_delay_ms(1000);
			for(j=0;j<10;j++)
			{
				SSD_voidSendNumber(SSD2,j);
				_delay_ms(1000);
			}
		}




	}

}
