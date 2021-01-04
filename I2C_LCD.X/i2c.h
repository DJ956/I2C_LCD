
#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

void i2c_wait();
void i2c_start();
void i2c_stop();
void i2c_repeated_start();
void i2c_write(uint8_t data);
uint8_t i2c_read(uint8_t ack);
    
#ifdef	__cplusplus
}
#endif

#endif	/* LCD_LIB_H */
