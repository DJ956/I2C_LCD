/*
 * File:   i2c_lib.c
 * Author: dexte
 *
 * Created on October 4, 2020, 3:50 PM
 */


#include <xc.h>
#include "i2c_lib.h"

#define LCD_ADD 0x3F

#define _XTAL_FREQ 16000000

void I2C_Master_Init(){   
    SSP2STAT = 0x00;
    SSP2CON1 = 0b00101000;
    SSP2CON2 = 0x00;    
    //SSP2ADD  = LCD_ADD;
    SSP2ADD =  (_XTAL_FREQ/(4*100000))-1;
    SSP2CON1bits.SSPEN = 0;    
    
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB5 = 1;
}

void I2C_Master_Wait(){
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Start(){
    I2C_Master_Wait();
    SSP2CON2bits.SEN = 1;
}

void I2C_Master_Stop(){
    I2C_Master_Wait();
    SSP2CON2bits.PEN = 1;
}

void I2C_Master_Write(unsigned data){
    I2C_Master_Wait();
    SSP2BUF  = data;
}