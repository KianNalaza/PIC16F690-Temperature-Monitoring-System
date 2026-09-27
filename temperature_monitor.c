/*
 * File:   main.c
 * Author: Kian
 *
 * Created on 04 April 2026, 15:02
 */

#include <xc.h>
#define _XTAL_FREQ 4000000 // 4Mhz
#pragma config FOSC=INTRCIO, WDTE=OFF, PWRTE=OFF, MCLRE=ON, CP=OFF, \
CPD = OFF, BOREN = OFF, IESO = OFF, FCMEN = OFF
        void main(void){
    unsigned char multiplicand = 10;
    unsigned char multiplier = 5;
    int product = 0;
    while (multiplier > 0) {
        product += multiplicand;
        multiplier--;
    }
}
