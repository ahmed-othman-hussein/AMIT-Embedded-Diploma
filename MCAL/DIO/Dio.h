#ifndef DIO_H
#define DIO_H
#include "Dio_cfg.h"

typedef enum
{
 /* PORTA Pins */ 
 Pa0 = 0,
 Pa1 ,
 Pa2 ,
 Pa3 ,
 Pa4 ,
 Pa5 ,
 Pa6 ,
 Pa7 ,
 /* PORTB Pins */ 
 Pb0 ,
 Pb1 ,
 Pb2 ,
 Pb3 ,
 Pb4 ,
 Pb5 ,
 Pb6 ,
 Pb7 ,
 /* PORTC Pins */ 
 Pc0 ,
 Pc1 ,
 Pc2 ,
 Pc3 ,
 Pc4 ,
 Pc5 ,
 Pc6 ,
 Pc7 ,
 /* PORTD Pins */ 
 Pd0 ,
 Pd1 ,
 Pd2 ,
 Pd3 ,
 Pd4 ,
 Pd5 ,
 Pd6 ,
 Pd7 ,
 /* Number of Dio Pins */ 
 PinCount
  
}Dio_Pin_t;


extern void Dio_init(void);

/*  */
extern void Dio_setPin(Dio_Pin_t pinNum);


extern void Dio_clrPin(Dio_Pin_t pinNum);

extern Dio_pinState_t Dio_getPin(Dio_Pin_t pinNum);
























#endif /* DIO_H*/



