/*
 * SPI_Interface.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "SPI_Private.h"
#include "SPI_Config.h"
void SPI_Write(char data);
char SPI_Read();
void M_SPI_VoidMasterInit(void);
void M_SPI_VoidSlaveInit(void);
void M_SPI_VoidPrescalerSelect(u8 Prescaler);
u8 M_SPI_u8Transceive(u8 Copy_u8Data);
#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
