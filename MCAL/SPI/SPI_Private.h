/*
 * SPI_Private.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_
#include "DIO_Interface.h"
#include "STD.h"
#include "BitMath.h"


#define   SPCR               *((volatile u8 *)0x2D)
#define   SPSR               *((volatile u8 *)0x2E)
#define   SPDR               *((volatile u8 *)0x2F)

//SPCR

#define SPR0_BIT                 0
#define SPR1_BIT                 1
#define CPHA_BIT                 2
#define CPOL_BIT                 3
#define MSTR_BIT                 4
#define DORD_BIT                 5
#define SPE_BIT                  6
#define SPIE_BIT                 7

//SPSR
#define SPI2X_BIT                0
#define WCOL_BIT                 6
#define SPIF_BIT                 7

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
