
#include "mcc_generated_files/mcc.h"
#include "i2c_lib.h"
#include "lcd_lib.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    I2C_Master_Init();    
    
    uint8_t msg[] = "hello";
    
    lcd_init();
    lcd_clear();
    lcd_cmd(0x02);
    lcd_str(msg);
    
    while (1)
    {
        
    }
}
/**
 End of File
*/