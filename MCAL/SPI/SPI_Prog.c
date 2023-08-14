/*
 * SPI_Prog.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed
 */

#include "SPI_Interface.h"
#include "avr/interrupt.h"
volatile u8 Received=0;


void M_SPI_VoidMasterInit(void)
{

	M_DIO_Void_SetPinDirection(SPI_SS_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SPI_MOSI_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SPI_MISO_PIN, INPUT);
	M_DIO_Void_SetPinDirection(SPI_SCK_PIN, OUTPUT);

	SET_BIT(SPCR,MSTR_BIT);
	SET_BIT(SPCR,SPE_BIT);


#if (SPI_INTERRUPT_ENABLE_CONFG == SPI_INTERRUPT_ENABLE)

	SET_BIT(SPCR,SPIE_BIT);

#endif

	/*****************************************/
}
void M_SPI_VoidSlaveInit(void){

	M_DIO_Void_SetPinDirection(SPI_SS_PIN, INPUT);
	M_DIO_Void_SetPinDirection(SPI_MOSI_PIN, INPUT);
	M_DIO_Void_SetPinDirection(SPI_MISO_PIN, OUTPUT);
	M_DIO_Void_SetPinDirection(SPI_SCK_PIN, INPUT);


	SET_BIT(SPCR,SPE_BIT);
	CLR_BIT(SPCR,MSTR_BIT);

#if (SPI_INTERRUPT_ENABLE_CONFG == SPI_INTERRUPT_ENABLE)

	SET_BIT(SPCR,SPIE_BIT);

#endif

}
u8 M_SPI_u8Transceive(u8 Copy_u8Data)
{
	SPDR=Copy_u8Data;

	while(!(SPSR & (1<<SPIF)));
	return SPDR ;
}



void SPI_Write(char data)
{

	SPDR = data;
	while(!(SPSR & (1<<SPIF_BIT)));
	u8 buffer;
	buffer = SPDR;
}

char SPI_Read()
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF_BIT)));
	return(SPDR);
}

void M_SPI_VoidPrescalerSelect(u8 Prescaler)
{

#if (SPI_PRESCALER_SELECT == SPI_PRESCALER_DIV_BY_2)
	CLR_BIT(SPCR,SPR0_BIT);
	CLR_BIT(SPCR,SPR1_BIT);
	SET_BIT(SPSR,SPI2X_BIT);
#elif (SPI_PRESCALER_SELECT == SPI_PRESCALER_DIV_BY_4)
	CLR_BIT(SPCR,SPR0_BIT);
	CLR_BIT(SPCR,SPR1_BIT);
	CLR_BIT(SPSR,SPI2X_BIT);
#elif (SPI_PRESCALER_SELECT == SPI_PRESCALER_DIV_BY_8)
	SET_BIT(SPCR,SPR0_BIT);
	CLR_BIT(SPCR,SPR1_BIT);
	SET_BIT(SPSR,SPI2X_BIT);
#elif (SPI_PRESCALER_SELECT == SPI_PRESCALER_DIV_BY_16)
	SET_BIT(SPCR,SPR0_BIT);
	CLR_BIT(SPCR,SPR1_BIT);
	CLR_BIT(SPSR,SPI2X_BIT);

#elif (SPI_PRESCALER_SELECT == SPI_PRESCALER_DIV_BY_32)
	CLR_BIT(SPCR,SPR0_BIT);
	SET_BIT(SPCR,SPR1_BIT);
	SET_BIT(SPSR,SPI2X_BIT);
#elif (SPI_PRESCALER_SELECT == SPI_PRESCALER_DIV_BY_64)
	SET_BIT(SPCR,SPR0_BIT);
	SET_BIT(SPCR,SPR1_BIT);
	SET_BIT(SPSR,SPI2X_BIT);
#elif (SPI_PRESCALER_SELECT == SPI_PRESCALER_DIV_BY_128)
	SET_BIT(SPCR,SPR0_BIT);
	SET_BIT(SPCR,SPR1_BIT);
	CLR_BIT(SPSR,SPI2X_BIT);

#endif

}

#if (SPI_INTERRUPT_ENABLE_CONFG == SPI_INTERRUPT_ENABLE)

ISR(SPI_STC_vect)
{
	Received++;
}

#endif
