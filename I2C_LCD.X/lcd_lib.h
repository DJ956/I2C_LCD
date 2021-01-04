/* 
 * File:   lcd_lib.h
 * Author: dexte
 *
 * Created on December 6, 2020, 9:58 PM
 */

#ifndef LCD_LIB_H
#define	LCD_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LCD_ADD 0x3F
    
#define En 0b00000100
#define Rs 0b00000001

    void lcd_init();
    void lcd_backlight();    
    void lcd_cmd(uint8_t cmd);
    void lcd_clear();
    void lcd_set_cursor(uint8_t col, uint8_t row);
    void lcd_print();
    
    void command(uint8_t val, uint8_t mode);
    
#ifdef	__cplusplus
}
#endif

#endif	/* LCD_LIB_H */

