
#include "mcc_generated_files/mcc.h"

#include "i2c.h"
#include "lcd_lib.h"

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();     
     
    WPUB = 0x24;
    OPTION_REGbits.nWPUEN = 0;
    
    SSP2ADD = 0x13;    
    SSP2CON1 = 0x28;
    SSP2CON2 = 0x0;
    SSP2STAT = 0;
    
    lcd_init();
    lcd_backlight();
    lcd_set_cursor(0, 0);
    
    lcd_print("HIZ");   
    
    __delay_ms(1000);
    
    lcd_set_cursor(3, 0);
    lcd_print("12:00");
    
    while(1){}
}
/**
 End of File
*/