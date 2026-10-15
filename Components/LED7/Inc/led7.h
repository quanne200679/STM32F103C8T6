#ifndef __LED7__
#define __LED7__
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include <stm32f103xb.h>

typedef struct {
    GPIO_TypeDef *PORT;
    uint16_t PIN;
}LED7_GPIO_t;

typedef enum{
    LED_ANODE,
    LED_CATHODE,
}LED7_Type_t;

typedef struct{
    LED7_Type_t type;
    LED7_GPIO_t seg[8];
}LED7_t;

extern LED7_t led7;
extern uint8_t seg7[16];

void Init_LED7( GPIO_TypeDef *pa, uint16_t pina,
                GPIO_TypeDef *pb, uint16_t pinb,
                GPIO_TypeDef *pc, uint16_t pinc,
                GPIO_TypeDef *pd, uint16_t pind,
                GPIO_TypeDef *pe, uint16_t pine,
                GPIO_TypeDef *pf, uint16_t pinf,
                GPIO_TypeDef *pg, uint16_t ping,
                GPIO_TypeDef *ph, uint16_t pinh,
                LED7_Type_t ty
);


void Display_LED7(uint8_t num);

#endif