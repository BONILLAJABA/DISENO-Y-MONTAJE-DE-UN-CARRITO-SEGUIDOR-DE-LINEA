

#include <xc.h>//libreria
#include <pwm.h>//libreria pwm.


//BITS DE CONFIGURACION DEl PIC.....
#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, VREGEN = OFF
#pragma config WDT = OFF, WDTPS = 32768
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
#define _XTAL_FREQ 48000000



void main() {

TRISCbits.RC2 = 0;//motor 1
TRISCbits.RC1 = 0;//motor 2
TRISBbits.RB5 = 0;//motor 1 reversa
TRISBbits.RB4 = 0;//motor 2reversa
 
//OpenTimer2(T2_PS_1_16);//las cofiguraciones del pwm y el prescaler a utilizar es 16
//OpenPWM1(187); //PWM1 trabaja a 4KHz.
//OpenPWM2(187); //PWM2 trabaja a 4KHz.

TRISBbits.TRISB3 = 1; //RB3 es entrada sensor 1.
TRISBbits.TRISB2 = 1; //RB2 es entrada sensor 2.
TRISBbits.TRISB1 = 1; //RB1 es entrada sensor 3.
TRISBbits.TRISB0 = 1; //RB0 es entrada sensor 4.


while(1){

    //Línea recta.
    if (PORTBbits.RB3 == 1 && PORTBbits.RB2 == 0 && PORTBbits.RB1==0 && PORTBbits.RB0 == 1 ){//verifica si los dos sensores B0 y B1 estan en 1 para que el motor avanze.
        RC2=1;//motor1
        RC1=1;//motor2
        
        
      
    }
    
    //Curvas sencillas
    
    if (PORTBbits.RB3 == 1 && PORTBbits.RB0 == 0){//Verifica si el sensor 1 esta en 1 y el sensor 4 esta en 0 apaga el motor2
      RC2=1; //motor 1
      RC1=0; //motor 2
      }
    if (PORTBbits.RB3 == 0 && PORTBbits.RB0 == 1  ){//verifica si el sensor 4 esta en 1 y el sensor 1 esta en a enciende el motor2
        RC2=0; //motor1
        RC1=1; //motor2
        }
    
    //Para Cruz calle
    else if (PORTBbits.RB3 == 0 && PORTBbits.RB2 == 0 && PORTBbits.RB1==0 && PORTBbits.RB0 == 0 ){//verifica si senores A B C D estan en negro como cruz calle para seguir caminando
          RC1=1;
          RC2=1;
          
      }
    
        
    //GIROS 90°
    if (PORTBbits.RB3 == 0 && PORTBbits.RB2 == 0 && PORTBbits.RB1==0 && PORTBbits.RB0 == 1 ){//90° izquierda
        RC2=0; //motor 1  
        RC1=1; //motor 2
        }
    
        
    if (PORTBbits.RB3 == 1 && PORTBbits.RB2 == 1 && PORTBbits.RB1==1 && PORTBbits.RB0 == 0 ){// 90° derecha
        RC2=1;  //motor1
        RC1=0;  //motor 2 
    }
    
    //if (PORTBbits.RB3 == 1 && PORTBbits.RB2 == 1 && PORTBbits.RB1==1 && PORTBbits.RB0 == 1 ){//reversa
      //  RC2=0;
        //RC1=0;
        //RD0=1; //motor 1  
        //RD1=1; //motor 2
      //}
    
    if (PORTBbits.RB3 == 1 && PORTBbits.RB2 == 1 && PORTBbits.RB1==1 && PORTBbits.RB0 == 1 ){//no caminar
      RB5=1; RB4=1;
      }
               
   
    
}
    } ;//se repitira el ciclo infintamente }