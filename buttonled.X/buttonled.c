#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "buttonled.h"
#define _XTAL_FREQ 4000000
#define led PORTBbits.RB0
#define button PORTBbits.RB1
 
char b = 1;
void buttonled_init(void){
    TRISB = 0x02; // 0b0000 0010   outputs are 0 | inputs are 1
    PORTB = 0x00;
}

void button_driver(void){
    while(1){
        if(button){
            while(button);
            b ^= 1;
        } 
        switch(b){
            case 1:
                led ^= 1;__delay_ms(500);
                break;
            case 0:
                led = 1;
                break;
        }
    }
}