/* 
 * File:   i2c_lib.h
 * Author: dexte
 *
 * Created on October 4, 2020, 3:45 PM
 */

#ifndef I2C_LIB_H
#define	I2C_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

    void I2C_Master_Init();
    void I2C_Master_Start();
    void I2C_Master_Stop();
    void I2C_Master_Wait();
    void I2C_Master_Write(unsigned data);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_LIB_H */

