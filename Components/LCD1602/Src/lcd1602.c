#include "lcd1602.h"

LCD mLCD;

void LCD_Write_Byte(uint8_t data, uint8_t mode){
    if(mode == 0x01){
        //truyen data RS = 1; RS = PB0
        HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.RS, 1); 
    }
    else if(mode == 0x00){
        //truyen cmd RS = 0; RS = PB0
        HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.RS, 0);
    }
    HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D0, (data & 0x01) ? 1 : 0);
    HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D1, (data & 0x02) ? 1 : 0);
    HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D2, (data & 0x04) ? 1 : 0);
    HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D3, (data & 0x08) ? 1 : 0);
    HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D4, (data & 0x10) ? 1 : 0);
    HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D5, (data & 0x20) ? 1 : 0);
    HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D6, (data & 0x40) ? 1 : 0);
    HAL_GPIO_WritePin(mLCD.PORT_DATA, mLCD.D7, (data & 0x80) ? 1 : 0);

    HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.E, 1);     // E = PB10 = 0
    HAL_Delay(1);                                 // tạo cạnh xuống
    HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.E, 0);     //
    HAL_Delay(1);
    //HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.E, 1);
    //HAL_Delay(1);
} 

void LCD_Write_data(uint8_t data){
    LCD_Write_Byte(data, 1);
}

void LCD_Write_cmd(uint8_t data){
    LCD_Write_Byte(data, 0);
}
void LCD_Init(){
  HAL_GPIO_WritePin(mLCD.PORT_R,mLCD.RW,0);
  HAL_GPIO_WritePin(mLCD.PORT_R, mLCD.E, 0);
  HAL_Delay(50);
  LCD_Write_cmd(0x38);     //Function set (8-bit interface, 2 lines, 5*7 Pixels)
  HAL_Delay(5);  
  LCD_Write_cmd(0x0C);      //Restore
  HAL_Delay(5);
  LCD_Write_cmd(0x01);      //reset
  HAL_Delay(5);
  LCD_Write_cmd(0x06);
  HAL_Delay(5);
}

void LCD_Print_data(char *str){
  while(*str){
    LCD_Write_data(*str++);
  }

}