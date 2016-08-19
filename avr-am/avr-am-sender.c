// designed for and tested with ATTiny44A
// modded for ATTiny85, using PB1 for sound out

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>


void beep(){
    for(char i=50;i;i--){
        DDRB|=_BV(PB1);_delay_ms(1);
        DDRB&=~_BV(PB1);_delay_ms(1);
    }
}

void rest(){_delay_ms(100);}

void dot(){beep();rest();}
void dash(){beep();beep();beep();rest();}
void space(){rest();rest();}
void space2(){space();space();}

// SACHA KNOPKINA
// ... / .- / -.-. / .... / .- / -.- / -. / --- / .--. / -.- / .. / -. / .-

int main(){
    DDRB|=_BV(PB1);
    for(;;){
        dot(); dot(); dot(); space();               // S
        dot(); dash(); space();                     // A
        dash(); dot(); dash(); dot(); space();      // C
        dot(); dot(); dot(); dot(); space();        // H
        dot(); dash(); space();                     // A
        space2();
        dash(); dot(); dash(); space();             // K
        dash(); dot(); space();                     // N
        dash(); dash(); dash(); space();            // O
        dot(); dash(); dash(); dot(); space();      // P
        dash(); dot(); dash(); space();             // K
        dot(); dot(); space();                      // I
        dash(); dot(); space();                     // N
        dot(); dash(); space();                     // A
        _delay_ms(1000); // silence
    }
    return 0;
}
