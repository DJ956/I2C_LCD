/* 
 * File:   lcd_lib.h
 * Author: dexte
 *
 * Created on October 4, 2020, 3:24 PM
 */

#ifndef LCD_LIB_H
#define	LCD_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

void lcd_init();
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_clear();
void lcd_str(const uint8_t* ptr);



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_LIB_H */

