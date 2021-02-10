#ifndef DIO_CFG_H
#define DIO_CFG_H

typedef enum
{
  Dio_LOW =0,
  Dio_HIGH 
  
}Dio_pinState_t;



  typedef enum
  {
    output=0,
    input,
	inputwithpullup
  }Dio_Dir_t;
  
  
  
  typedef struct
  {
    Dio_Dir_t       pinDirection;
    Dio_pinState_t  initState;
    
  }Dio_pin_cfg_t;


  extern const Dio_pin_cfg_t Dio_pin_cfg[];
  



#endif /* DIO_CFG_H */
