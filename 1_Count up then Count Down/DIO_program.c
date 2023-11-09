/****************************************************************/
/****************************************************************/
/**************   Author: Youssef  Ahmed	*********************/
/**************   Layer: MCAL				*********************/
/**************   SWC: DIO					*********************/
/**************   Version: 1.00				*********************/

#include "DIO_interface.h"
#include "DIO_private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction)
{
	DIO_ErrorStatus Error_state =DIO_OK;

	if((Copy_u8PIN<=DIO_PIN7)&&(Copy_u8PORT<=DIO_PORTD))
	{

		if(Copy_u8Direction==DIO_PIN_OUTPUT)
		{
		switch(Copy_u8PORT)
			{
			case DIO_PORTA: SETBIT(DDRA_Register,Copy_u8PIN); break;
			case DIO_PORTB: SETBIT(DDRB_Register,Copy_u8PIN); break;
			case DIO_PORTC: SETBIT(DDRC_Register,Copy_u8PIN); break;
			case DIO_PORTD: SETBIT(DDRD_Register,Copy_u8PIN); break;
			}
		}
		else if(Copy_u8Direction==DIO_PIN_INPUT)
		{
			switch(Copy_u8PORT)
				{
				case DIO_PORTA: CLRBIT(DDRA_Register,Copy_u8PIN); break;
				case DIO_PORTB: CLRBIT(DDRB_Register,Copy_u8PIN); break;
				case DIO_PORTC: CLRBIT(DDRC_Register,Copy_u8PIN); break;
				case DIO_PORTD: CLRBIT(DDRD_Register,Copy_u8PIN); break;
				}

		}
	}
		else

		{
			DIO_ErrorStatus Error_state =DIO_NOK;

		}
	return Error_state;
}


DIO_ErrorStatus DIO_enumSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{	DIO_ErrorStatus Error_state =DIO_OK;
	if((Copy_u8PIN<=DIO_PIN7)&&(Copy_u8PORT<=DIO_PORTD))
		{

			if(Copy_u8Value==DIO_PIN_HIGH)
			{
			switch(Copy_u8PORT)
				{
				case DIO_PORTA: SETBIT(PORTA_Register,Copy_u8PIN); break;
				case DIO_PORTB: SETBIT(PORTB_Register,Copy_u8PIN); break;
				case DIO_PORTC: SETBIT(PORTC_Register,Copy_u8PIN); break;
				case DIO_PORTD: SETBIT(PORTD_Register,Copy_u8PIN); break;
				}
			}

			else if(Copy_u8Value==DIO_PIN_LOW)
			{
				switch(Copy_u8PORT)
				{
					case DIO_PORTA: CLRBIT(PORTA_Register,Copy_u8PIN); break;
					case DIO_PORTB: CLRBIT(PORTB_Register,Copy_u8PIN); break;
					case DIO_PORTC: CLRBIT(PORTC_Register,Copy_u8PIN); break;
					case DIO_PORTD: CLRBIT(PORTD_Register,Copy_u8PIN); break;
				}

			}
		}
	else
	{
		DIO_ErrorStatus Error_state =DIO_NOK;
	}

	return Error_state;
}


DIO_ErrorStatus DIO_enumGetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData)
{
	DIO_ErrorStatus Error_state =DIO_OK;
	if((Copy_u8PIN<=DIO_PIN7)&&(Copy_u8PORT<=DIO_PORTD))
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: * Copy_PtrData = GETBIT(PINA_Register,Copy_u8PIN); break;
			case DIO_PORTB: * Copy_PtrData = GETBIT(PINB_Register,Copy_u8PIN); break;
			case DIO_PORTC: * Copy_PtrData = GETBIT(PINC_Register,Copy_u8PIN); break;
			case DIO_PORTD: * Copy_PtrData = GETBIT(PIND_Register,Copy_u8PIN); break;
		}


	}
	else
	{
		DIO_ErrorStatus Error_state =DIO_NOK;
	}
	
	return Error_state;
}


DIO_ErrorStatus DIO_enumTogglePinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	DIO_ErrorStatus Error_state =DIO_OK;
	if((Copy_u8PIN<=DIO_PIN7)&&(Copy_u8PORT<=DIO_PORTD))
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: TOGGLEBIT(PORTA_Register,Copy_u8PIN); break;
			case DIO_PORTB: TOGGLEBIT(PORTB_Register,Copy_u8PIN); break;
			case DIO_PORTC: TOGGLEBIT(PORTC_Register,Copy_u8PIN); break;
			case DIO_PORTD: TOGGLEBIT(PORTD_Register,Copy_u8PIN); break;
		}

	}
	else
	{
		DIO_ErrorStatus Error_state =DIO_NOK;
	}
	
	return Error_state;
}


DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Direction)
{			DIO_ErrorStatus Error_state =DIO_OK;

	if(Copy_u8PORT<=DIO_PORTD)
	{
		switch(Copy_u8PORT)
		{
		case DIO_PORTA: DDRA_Register = Copy_u8Direction; break;
		case DIO_PORTB: DDRB_Register = Copy_u8Direction; break;
		case DIO_PORTC: DDRC_Register = Copy_u8Direction; break;
		case DIO_PORTD: DDRD_Register = Copy_u8Direction; break;

		}
	}
	else
	{
		DIO_ErrorStatus Error_state =DIO_NOK;
	}

		return Error_state;


}


DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8PORT, u8 Copy_u8Value)
{
	DIO_ErrorStatus Error_state =DIO_OK;


	if(Copy_u8PORT<=DIO_PORTD)
	{

		switch(Copy_u8PORT)
		{
			case DIO_PORTA: PORTA_Register = Copy_u8Value; break;
			case DIO_PORTB: PORTB_Register = Copy_u8Value; break;
			case DIO_PORTC: PORTC_Register = Copy_u8Value; break;
			case DIO_PORTD: PORTD_Register = Copy_u8Value; break;
		}
	}

	else
	{
		DIO_ErrorStatus Error_state =DIO_NOK;
	}

	return Error_state;
}


DIO_ErrorStatus DIO_enumGetPortValue(u8 Copy_u8PORT, u8 * Copy_PtrData)
{
	DIO_ErrorStatus Error_state =DIO_OK;


		if(Copy_u8PORT<=DIO_PORTD)
		{

			switch(Copy_u8PORT)
			{
				case DIO_PORTA:* Copy_PtrData = PINA_Register ; break;
				case DIO_PORTB:* Copy_PtrData = PINB_Register ; break;
				case DIO_PORTC:* Copy_PtrData = PINC_Register ; break;
				case DIO_PORTD:* Copy_PtrData = PIND_Register ; break;
			}
		}

		else
		{
			DIO_ErrorStatus Error_state =DIO_NOK;
		}

		return Error_state;

}


DIO_ErrorStatus DIO_enumTogglePortValue(u8 Copy_u8PORT)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;

		if (Copy_u8PORT <= DIO_PORTD)
		{
			switch (Copy_u8PORT)
			{
			case DIO_PORTA : PORTA_Register = ~PORTA_Register ;
			break ;
			case DIO_PORTB : PORTB_Register = ~PORTB_Register ;
			break ;
			case DIO_PORTC : PORTC_Register = ~PORTC_Register ;
			break ;
			case DIO_PORTD : PORTD_Register = ~PORTD_Register ;
			break ;
			}
		}
		else
		{
			LOC_enumState = DIO_NOK;
		}
		return LOC_enumState ;

}
