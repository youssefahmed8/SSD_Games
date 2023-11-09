/****************************************************************/
/****************************************************************/
/**************   Author: Youssef  Ahmed	*********************/
/**************   Layer: HAL				*********************/
/**************   SWC: SSD					*********************/
/**************   Version: 1.00				*********************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_
#include "STD_TYPES.h"




#define SSD_PORTA	0
#define SSD_PORTB	1
#define SSD_PORTC	2
#define SSD_PORTD	3



#define SSD_PIN0	0
#define SSD_PIN1 	1
#define SSD_PIN2	2
#define SSD_PIN3	3
#define	SSD_PIN4	4
#define	SSD_PIN5	5
#define SSD_PIN6	6
#define SSD_PIN7	7

#define COMMON_CATHOD    1
#define COMMON_ANODE     0





typedef struct{

	u8 Com_Type; //Type of 7-segment common cathode or common anode
	u8 Port;
	u8 Enable_Port;
	u8 Enable_Pin ;
}SSD_Type;


void SSD_voidInit       	 ( SSD_Type SSD_Configuration );

void SSD_voidEnable          ( SSD_Type SSD_Configuration );

void SSD_voidDisable         ( SSD_Type SSD_Configuration );

void SSD_voidSendNumber      ( SSD_Type SSD_Configuration ,u8 Copy_u8value);


void SSD_voidSendSpecificNumber      ( SSD_Type SSD_Configuration ,u8 Copy_u8value);






#endif
