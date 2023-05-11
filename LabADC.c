//Primera sección
#include <xc.h> //libreria de todos los los PICs
#define _XTAL_FREQ 100000//Poner la frecuencia del oscilador (1 MHz por defecto))
#pragma config FOSC=INTOSC_EC
#pragma config WDT=OFF
unsigned char Conversion(void);
void main(void){
    unsigned char a;
    TRISA0=1;
    ADCON0=0b00000001;
    ADCON1=0b00001110;
    ADCON2=0b00001000;
    while(1){
        a=Conversion();
    }
}
unsigned char Conversion(void){
    GO=1;
    while(GO==1);
    return ADRESH;
}
