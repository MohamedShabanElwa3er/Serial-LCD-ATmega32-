/*
 * LDR_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

/*--------------------------------------------------------------------------------------------*/
/*   SELECT MICROCONTROLERS PINS   */
/*--------------------------------------------------------------------------------------------*/
#define LCD_D0_PIN                PA0_PIN
#define LCD_D1_PIN                PA1_PIN
#define LCD_D2_PIN                PA2_PIN
#define LCD_D3_PIN                PA3_PIN
#define LCD_D4_PIN                PB0_PIN
#define LCD_D5_PIN                PB1_PIN
#define LCD_D6_PIN                PB2_PIN
#define LCD_D7_PIN                PB4_PIN
#define LCD_RS_PIN                PA3_PIN
#define LCD_EN_PIN                PA2_PIN

/*--------------------------- SPI_SERIAL_CONNECTION_8BIT_BASED----------------------------------------------------*/
#define TRIGGER_PIN                 23
#define ENABLE_SPI_MODE             1
#define DISABLE_SPI_MODE            0
#define SPI_MODE_SELECT           ENABLE_SPI_MODE
/*--------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------*/
/*   LCD_MODE OPTIONS :  [ _4_BIT_MODE , _8_BIT_MODE ]   */
/*--------------------------------------------------------------------------------------------*/
#define LCD_MODE           _8_BIT_MODE

#endif /* HAL_LCD_LCD_CONFIG_H_ */
