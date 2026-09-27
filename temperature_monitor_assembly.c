/*
 * File:   main.c
 * Author: Kian
 *
 * Created on 02 April 2026, 12:25
 */


#include <xc.h>
#define _XTAL_FREQ 4000000 // 4Mhz
// Set config word
#pragma config FOSC=INTRCIO, WDTE=OFF, PWRTE=OFF, MCLRE=ON, \
CP=OFF, CPD=OFF, BOREN=OFF, IESO=OFF, FCMEN=OFF
int get7SegmentCode(int value) {
 switch(value) {
 case 0: return 0b00111111;
 case 1: return 0b00000110;
 case 2: return 0b01011011;
 case 3: return 0b01001111;
 case 4: return 0b01100110;
 case 5: return 0b01101101;
 case 6: return 0b01111101;
 case 7: return 0b00000111;
 case 8: return 0b01111111;
 case 9: return 0b01101111;
 case 72: return 0b01110110; // H
 case 73: return 0b00000110; // I
 case 76: return 0b00111000; // L
 case 79: return 0b00111111; // O
 }
}
void displayNumber(int number) {
 int tens, units;
 if(number<0){tens=76; units=79;}
 else if(number>99){tens=72; units=73;}
 else {tens = number/10; units = number%10;}

 RA4 = 0; // units
 RA5 = 1; // tens
 int unitsCode = get7SegmentCode(units);
 PORTC = unitsCode & 0b0000001; __delay_ms(1);
 PORTC = unitsCode & 0b0000010; __delay_ms(1);
 PORTC = unitsCode & 0b0000100; __delay_ms(1);
 PORTC = unitsCode & 0b0001000; __delay_ms(1);
 PORTC = unitsCode & 0b0010000; __delay_ms(1);
 PORTC = unitsCode & 0b0100000; __delay_ms(1);
 PORTC = unitsCode & 0b1000000; __delay_ms(1);
 PORTC = 0x00;

 RA4 = 1; // units
 RA5 = 0; // tens
 int tensCode = get7SegmentCode(tens);
 PORTC = tensCode & 0b0000001; __delay_ms(1);
 PORTC = tensCode & 0b0000010; __delay_ms(1);
 PORTC = tensCode & 0b0000100; __delay_ms(1);
 PORTC = tensCode & 0b0001000; __delay_ms(1);
 PORTC = tensCode & 0b0010000; __delay_ms(1);
 PORTC = tensCode & 0b0100000; __delay_ms(1);
 PORTC = tensCode & 0b1000000; __delay_ms(1);
 PORTC = 0x00;
}

void main(void) {
 // Task 1: Configure the ports
 TRISA = 0;
 TRISC = 0;
 ANSEL = 0;
 ANSELH = 0;
 TRISAbits.TRISA2 = 1;
 ANSELbits.ANS2 = 1;

 ADCON0bits.ADFM = 1;
 ADCON0bits.VCFG = 0;
 ADCON1bits.ADCS = 0b001;
 ADCON0bits.CHS = 2;
 ADCON0bits.ADON = 1;

 // Task 2: Initialise the AD converter
 while(1){
    __delay_us(5);
    ADCON0bits.GO=1;
    while(ADCON0bits.GO==1);
 // Task 3: Carry out conversion and update display
    int result = ((ADRESH<<8)+ADRESL);
    float conversion = 100.0 / 1023.0;
    int percentage = result * conversion;
    displayNumber(percentage);
 }
}
