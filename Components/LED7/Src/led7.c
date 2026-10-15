#include "led7.h"

LED7_t led7;
uint8_t seg7[16] = {
    0xC0,   // 0
    0xF9,   // 1
    0xA4,   // 2
    0xB0,   // 3
    0x99,   // 4
    0x92,   // 5
    0x82,   // 6
    0xF8,   // 7    
    0x80,   // 8
    0x90,   // 9    
    0x88,   // A
    0x83,   // B
    0xC6,   // C
    0xA1,   // D
    0x86,   // E
    0x8E   // F
};
void Init_LED7( GPIO_TypeDef *pa, uint16_t pina,
                GPIO_TypeDef *pb, uint16_t pinb,
                GPIO_TypeDef *pc, uint16_t pinc,
                GPIO_TypeDef *pd, uint16_t pind,
                GPIO_TypeDef *pe, uint16_t pine,
                GPIO_TypeDef *pf, uint16_t pinf,
                GPIO_TypeDef *pg, uint16_t ping,
                GPIO_TypeDef *ph, uint16_t pinh,
                LED7_Type_t ty
){
    led7.seg[0].PORT = pa; led7.seg[0].PIN = pina;
    led7.seg[1].PORT = pb; led7.seg[1].PIN = pinb;
    led7.seg[2].PORT = pc; led7.seg[2].PIN = pinc;
    led7.seg[3].PORT = pd; led7.seg[3].PIN = pind;
    led7.seg[4].PORT = pe; led7.seg[4].PIN = pine;
    led7.seg[5].PORT = pf; led7.seg[5].PIN = pinf;
    led7.seg[6].PORT = pg; led7.seg[6].PIN = ping;
    led7.seg[7].PORT = ph; led7.seg[7].PIN = pinh;
    led7.type = ty;
}



void Display_LED7(uint8_t num){
    if(num > 9) return;
    uint8_t data;
    switch(num){
        case 'A': 
            data = seg7[10];
            break;
        case 'B': 
            data = seg7[11];
            break;
        case 'C': 
            data = seg7[12];
            break;
        case 'D': 
            data = seg7[13];
            break;
        case 'E': 
            data = seg7[14];
            break;
        case 'F': 
            data = seg7[15];
            break;
        default:
            data = seg7[num];
    }
    
    if(led7.type == LED_ANODE){
        for(int i=0; i<=7; i++){
            HAL_GPIO_WritePin(led7.seg[i].PORT, led7.seg[i].PIN, ((data >> i)&0x01) ? 1 : 0);
        }
    }
    if(led7.type == LED_CATHODE){
        for(int i=0; i<=7; i++){
            HAL_GPIO_WritePin(led7.seg[i].PORT, led7.seg[i].PIN, ((data >> i)&0x01) ? 0 : 1);
        }
    }
}