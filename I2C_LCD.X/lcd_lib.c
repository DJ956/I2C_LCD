/*
 * File:   lcd_lib.c
 * Author: dexte
 *
 * Created on October 4, 2020, 2:52 PM
 */

#include <xc.h>

#include "mcc_generated_files/mcc.h"
#include "i2c_lib.h"
#include "lcd_lib.h"

#define LCD_ADD 0x3F

void lcd_cmd(uint8_t cmd){
    I2C_Master_Start();
    I2C_Master_Write(LCD_ADD);
    I2C_Master_Write(0x00);
    I2C_Master_Write(cmd);
    I2C_Master_Stop();
    __delay_ms(10);
}

void lcd_init(){
    __delay_ms(150);
    lcd_cmd(0x38);
    lcd_cmd(0x39);
    lcd_cmd(0x14);
    lcd_cmd(0x7f);
    
    lcd_cmd(0x6A);
    __delay_ms(300);
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);    
}

void lcd_clear(){
    lcd_cmd(0x01);
}

void lcd_data(uint8_t data){
    I2C_Master_Start();
    I2C_Master_Write(LCD_ADD);
    I2C_Master_Write(0x40);
    I2C_Master_Write(data);
    I2C_Master_Stop();
    __delay_ms(10);
}

void lcd_str(const uint8_t* ptr){
    while(*ptr != 0){
        lcd_data(*ptr++);
    }
}