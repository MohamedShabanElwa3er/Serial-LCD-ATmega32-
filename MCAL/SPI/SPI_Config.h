/*
 * SPI_Config.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

#define SPI_SS_PIN                 24
#define SPI_MOSI_PIN               25
#define SPI_MISO_PIN               26
#define SPI_SCK_PIN                27

#define SPI_POLING_ENABLE          0
#define SPI_INTERRUPT_ENABLE       1

#define SPI_INTERRUPT_ENABLE_CONFG            SPI_POLING_ENABLE


#define SPI_PRESCALER_DIV_BY_2                  0
#define SPI_PRESCALER_DIV_BY_4                  1
#define SPI_PRESCALER_DIV_BY_8                  2
#define SPI_PRESCALER_DIV_BY_16                 3
#define SPI_PRESCALER_DIV_BY_32                 4
#define SPI_PRESCALER_DIV_BY_64                 5
#define SPI_PRESCALER_DIV_BY_128                6

#define SPI_PRESCALER_SELECT                SPI_PRESCALER_DIV_BY_16

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
