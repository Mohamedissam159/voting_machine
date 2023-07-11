/*
 * voting_machine.c
 *
 * Created: 7/11/2023 3:25:09 PM
 *  Author: mohamed issam
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "BUT_interface.h"
#include "BUT_config.h"

#define  F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

u8 counter1=0;
u8 counter2=0;
u8 counter3=0;
u8 counter4=0;

int main(void)
{
	CLCD_vInit();
	BUT_vInit(BUT_PORT, BUT_A);
	BUT_vInit(BUT_PORT, BUT_B);
	BUT_vInit(BUT_PORT, BUT_C);
	BUT_vInit(BUT_PORT, BUT_D);
	BUT_vInit(BUT_PORT, BUT_RESET);
	
	
	CLCD_vGoToXY(0,0);
	CLCD_vSendString("A=0");
	CLCD_vGoToXY(0,12);
	CLCD_vSendString("B=0");
	CLCD_vGoToXY(1,0);
	CLCD_vSendString("C=0");
	CLCD_vGoToXY(1,12);
	CLCD_vSendString("D=0");
    while(1)
    {
        if (BUT_u8Read(BUT_PORT,BUT_A)==1)
        {
			counter1++;
			CLCD_vGoToXY(0,2);
			CLCD_vWriteNumber(counter1);
			
        }
		
		else if (BUT_u8Read(BUT_PORT,BUT_B)==1)
		{
			counter2++;
			CLCD_vGoToXY(0,14);
			CLCD_vWriteNumber(counter2);
		}
		
        else if (BUT_u8Read(BUT_PORT,BUT_C)==1)
        {
			counter3++;
			CLCD_vGoToXY(1,2);
			CLCD_vWriteNumber(counter3);
        }
		
		else if (BUT_u8Read(BUT_PORT,BUT_D)==1)
		{
			counter4++;
			CLCD_vGoToXY(1,14);
			CLCD_vWriteNumber(counter4);
		}
		
		else if (BUT_u8Read(BUT_PORT,BUT_RESET)==1)
		{
			counter1=0;
			counter2=0;
			counter3=0;
			counter4=0;
			CLCD_vGoToXY(0,2);
			CLCD_vWriteNumber(counter1);
			CLCD_vGoToXY(0,14);
			CLCD_vWriteNumber(counter2);
			CLCD_vGoToXY(1,2);
			CLCD_vWriteNumber(counter3);
			CLCD_vGoToXY(1,14);
			CLCD_vWriteNumber(counter4);
		}
		_delay_ms(200);
         
    }
}