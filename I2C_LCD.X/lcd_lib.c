/*
 * File:   lcd_lib.c
 * Author: dexte
 *
 * Created on October 4, 2020, 2:52 PM
 */

#include <xc.h>
#include "mcc_generated_files/device_config.h"

#include "i2c.h"
#include "lcd_lib.h"

#define ROW 2
#define COL 16

uint8_t _backlightval;

void lcd_cmd(uint8_t cmd){
    i2c_start();
    i2c_write(LCD_ADD);  
    i2c_write(cmd);
    i2c_stop();    
}

void lcd_data(uint8_t data){
    i2c_start();
    i2c_write(LCD_ADD);
    i2c_write(0x40);
    i2c_write(data);
    i2c_stop();    
}

void lcd_init(){
    __delay_ms(400);
    
    lcd_cmd(0x30);        
    __delay_us(10);
    lcd_cmd(0x34);    
    __delay_us(10);
    lcd_cmd(0x30);    
    __delay_ms(5);  //write4bits(0x03 << 4)
    
    lcd_cmd(0x30);    
    __delay_us(10);
    lcd_cmd(0x34);    
    __delay_us(10);
    lcd_cmd(0x30);
    __delay_ms(5);  //write4bits(0x03 << 4)
    
    lcd_cmd(0x30);
    __delay_us(10);    
    lcd_cmd(0x34);
    __delay_us(10);    
    lcd_cmd(0x30);
    __delay_us(300);  //write4bits(0x03 << 4)
    
    lcd_cmd(0x20);
    __delay_us(10);
    lcd_cmd(0x24);
    __delay_us(10);
    lcd_cmd(0x20);     
    __delay_us(10); //write4bits(0x02 << 4)
    
    //command(0x28)
    lcd_cmd(0x20);
    __delay_us(10);
    lcd_cmd(0x24);
    __delay_us(10);
    lcd_cmd(0x20);  //write4bits(0x20);
    
    __delay_us(100);
    
    lcd_cmd(0x80);
    __delay_us(10);
    lcd_cmd(0x84);
    __delay_us(10);
    lcd_cmd(0x80);  //write4bits(0x80)
    
    //display
    //command(0x0C)
    lcd_cmd(0x00);
    __delay_us(10);
    lcd_cmd(0x04);
    __delay_us(10);
    lcd_cmd(0x00);  //write4bits(0x00);
    
    __delay_us(100);
    
    lcd_cmd(0xC0);
    __delay_us(10);
    lcd_cmd(0xC4);
    __delay_us(10);
    lcd_cmd(0xC0);  //write4bits(0xC0);
    
    //clear
    //command(0x01);
    lcd_cmd(0x00);
    __delay_us(10);
    lcd_cmd(0x04);
    __delay_us(10);
    lcd_cmd(0x00);  //write4bits(0x00);
    
    __delay_us(100);
    
    lcd_cmd(0x10);
    __delay_us(10);
    lcd_cmd(0x14);
    __delay_us(10);
    lcd_cmd(0x10);  //write4bits(0x10);
    
    __delay_ms(5); //takes a long time
    
    //command(0x06);
    lcd_cmd(0x00);
    __delay_us(10);
    lcd_cmd(0x04);
    __delay_us(10);
    lcd_cmd(0x00);  //write4bits(0x00);
    
    __delay_us(100);
    
    lcd_cmd(0x60);
    __delay_us(10);
    lcd_cmd(0x64);
    __delay_us(10);
    lcd_cmd(0x60);  //write4bits(0x60);
    
    //home()
    //command(0x02)
    lcd_cmd(0x00);
    __delay_us(10);
    lcd_cmd(0x04);
    __delay_us(10);
    lcd_cmd(0x00);  //write4bits(0x00);
    
    __delay_us(100);
    
    lcd_cmd(0x20);
    __delay_us(10);
    lcd_cmd(0x24);
    __delay_us(10);
    lcd_cmd(0x20);  //write4bits(0x20);
    
    __delay_ms(3);
}

void lcd_backlight(){
    lcd_cmd(0x08);
    _backlightval = 0x08;
    __delay_us(10);
}

void lcd_set_cursor(uint8_t col, uint8_t row){
    uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    if(row > ROW){
        row = ROW - 1;
    }
    
    uint8_t cmd = 0x88 | (col + row_offsets[row]);
    //command()
    uint8_t highnib = (cmd & 0xf8);
	uint8_t lownib = ((cmd >> 4) & 0xf8);
    
	lcd_cmd(highnib);
    lcd_cmd(highnib | En);
    lcd_cmd(highnib & ~En);
    
    __delay_us(100);
        
	lcd_cmd(lownib);
    lcd_cmd(lownib | En);
    lcd_cmd(lownib & ~En);    
}

void lcd_print(char *str) {
    while (*str) {
        uint8_t cmd = *str++;
        uint8_t highnib = (cmd & 0xf0) | Rs;
        uint8_t lownib = ((cmd << 4) & 0xf0) | Rs;

        lcd_cmd(highnib | _backlightval);
        lcd_cmd(highnib | En | _backlightval);
        lcd_cmd(highnib & ~En | _backlightval);

        __delay_us(100);

        lcd_cmd(lownib | _backlightval);
        lcd_cmd(lownib | En | _backlightval);
        lcd_cmd(lownib & ~En | _backlightval);            
    }    
}