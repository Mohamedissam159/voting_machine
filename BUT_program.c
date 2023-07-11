/*
 * BUT_program.c
 *
 * Created: 7/11/2023 3:26:26 PM
 *  Author: mohamed issam
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "BUT_interface.h"
#include "BUT_config.h"

void BUT_vInit(u8 port, u8 pin)
{
	DIO_u8SetPinDirection(port,pin,0);
}

u8 BUT_u8Read(u8 port, u8 pin)
{
	return DIO_u8ReadPinValue(port, pin);
}