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

	SW_type SW1={PULLUP,DIO_PORTB,DIO_PIN7};
	SW_voidInit(SW1);

	int i=1,x,j;

	while(1)
	{
		DIO_enumGetPinValue(SW1.SW_Port,SW1.SW_Pin,&x);

		if(0 == x)
		{
			i=1;
			_delay_ms(20);
			if(0==x)
			{

				for(j=0;j<8;j++)
				{
					SSD_voidSendSpecificNumber(SSD1,i);
					_delay_ms(100);
					i<<=1;
					if(i==0b1000000)
					{
						i=0;
					}
				}



			}
		}
