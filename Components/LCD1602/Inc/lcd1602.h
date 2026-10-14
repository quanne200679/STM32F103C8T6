#ifndef LCD1602_H
#define LCD1602_H
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include <stm32f103xb.h>


#define MDATA 0x01
#define MCMD 0x00
/*
    RS & RW : PORT_R, RS 
    D0-D7: PORT_DATA
*/
typedef struct{
    GPIO_TypeDef *PORT_DATA;    //PORT cho D0-D7
    GPIO_TypeDef *PORT_R;       //PORT cho RW, RS, E
    uint16_t D0;
    uint16_t D1;
    uint16_t D2; 
    uint16_t D3;
    uint16_t D4;
    uint16_t D5;
    uint16_t D6;
    uint16_t D7;
    uint16_t RW;
    uint16_t RS;
    uint16_t E;
}LCD;

extern LCD mLCD;

void LCD_Init();
void LCD_Write_Byte(uint8_t data, uint8_t mode);
void LCD_Write_data(uint8_t data);
void LCD_Write_cmd(uint8_t data);
void LCD_Print_data(char *str);

#endif