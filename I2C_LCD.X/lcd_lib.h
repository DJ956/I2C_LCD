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

//#define LCD_ADD 0x3F
#define LCD_ADD 0x7E
//#define LCD_ADD 0x27
#define En 0b00000100

    void lcd_init();
    void lcd_backlight();    
    void lcd_cmd(uint8_t cmd);
    void lcd_data(uint8_t data);
    void lcd_clear();
    void lcd_set_cursor(uint8_t col, uint8_t row);
    void lcd_print();
    
#ifdef	__cplusplus
}
#endif

#endif	/* LCD_LIB_H */

