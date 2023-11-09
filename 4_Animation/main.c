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
	SSD_voidInit(SSD1);

	int i=1,j;

	while(1)
	{
		for(j=0;j<8;j++)
		{
			SSD_voidSendSpecificNumber(SSD1,i);
			_delay_ms(50);
			i<<=1;
			if(i==0b1000000)
			{
				i=1;
				j=-1;
			}
		}

	}

}
