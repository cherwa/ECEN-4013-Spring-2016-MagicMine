/*
 *@author Rahul Chidurala
 *@date 4/3/16
 */
#include "accel.h"

/**EXPECTING MSSP1/i2c1 module!!!
 * example usage
 * @code(.c)
 * if(initializeMPU())
    {
        if(testConnection())
        {
            LATAbits.LA0 = 1; //LED on means I2C working
            delay1Sec();
        }
        calculateOffset(1000); //calculates offsets
        while (1)
        {
            motionDetected = motionDetect();
            if(motionDetected)
            {
                LATAbits.LA0 = 1;
                __delay_ms(25);
                __delay_ms(25);
                __delay_ms(25);
                __delay_ms(25);
                motionDetected = 0; //reset motionDetected
                LATAbits.LA0 = 0;
            }
            __delay_ms(25);
            __delay_ms(25);
            __delay_ms(25);
            __delay_ms(25);

        }
    }
 * @endcode
 * 
 * 
 */

/**
 * Sets up the registers on the MPU6050 in order to read raw x,y,z accelerometer values
 * @return   true if initialization is successful
 */
bool initializeMPU()
{
    //Reset disabled, sleep disabled,cycle disabled, temp disabled, clk_sel 000 (internal)
    initializeSuccess &= I2C1dev_writeBytes(mpuAddress,PWR_MGMT_1_REG,1,PWR_MGMT_1_BITS);
    
    //self tests x,y,z off,range +-2000 degrees/s
    initializeSuccess &= I2C1dev_writeBytes(mpuAddress,GYRO_CONFIG_REG,1,GYRO_CONFIG_BITS);
    
    //self tests x,y,z off,range +-16g
    initializeSuccess &= I2C1dev_writeBytes(mpuAddress,ACCEL_CONFIG_REG,1,ACCEL_CONFIG_BITS);
    
    return initializeSuccess;
}

//combines high and low 8 bit number from _H and _L registers into one 16 bit unsigned number
//@param high   high byte
//@param low    low byte
//@return 16 bit unsigned number combined high and low byte
uint16_t combineHL(uint8_t high, uint8_t low)
{
    return ((high << 8) | low);
}

//takes the defined amount of samples and calculates the proper offsets in the given position
//example usage:    calculateOffset(1000);
//@param samples    the number of samples you want to average for calculating the offset, recommended value = 1000
//@return void
void calculateOffset(uint16_t samples)
{
    int tempX,tempY,tempZ; //for calculating offsets
    
    xaccel = axOff * (-1);
    yaccel = ayOff * (-1);
    zaccel = azOff * (-1);
    for(i_accel=0; i_accel<samples; i_accel++)
    {
        I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_H,1,&read_8_H); //reads X accel High data and stores in read_8_H
        I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_L,1,&read_8_L);
        tempX = combineHL(read_8_H,read_8_L);
        xaccel = xaccel/2 + tempX/2;

        I2C1dev_readBytes(mpuAddress,ACCEL_YOUT_H,1,&read_8_H);
        I2C1dev_readBytes(mpuAddress,ACCEL_YOUT_L,1,&read_8_L);
        tempY = combineHL(read_8_H,read_8_L);
        yaccel = yaccel/2 + tempY/2;
        
        I2C1dev_readBytes(mpuAddress,ACCEL_ZOUT_H,1,&read_8_H);
        I2C1dev_readBytes(mpuAddress,ACCEL_ZOUT_L,1,&read_8_L);
        tempZ = combineHL(read_8_H,read_8_L);
        zaccel = zaccel/2 + tempZ/2;
    }
    axOff = (-1) * xaccel;
    ayOff = (-1) * yaccel;
    azOff = (-1) * zaccel;
}

//compares current accelerometer values (with offset) and returns true if values exceed thresholds
//call this every 200 ms or so
//@param void
//@return   true if motion was detected
bool motionDetect(void)
{
    I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_H,1,&read_8_H); //reads X accel High data and stores in read_8_H
    I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_L,1,&read_8_L);
    xaccel = combineHL(read_8_H,read_8_L);
    
    I2C1dev_readBytes(mpuAddress,ACCEL_YOUT_H,1,&read_8_H);
    I2C1dev_readBytes(mpuAddress,ACCEL_YOUT_L,1,&read_8_L);
    yaccel = combineHL(read_8_H,read_8_L);
    
    I2C1dev_readBytes(mpuAddress,ACCEL_ZOUT_H,1,&read_8_H);
    I2C1dev_readBytes(mpuAddress,ACCEL_ZOUT_L,1,&read_8_L);
    zaccel = combineHL(read_8_H,read_8_L);
    
    xaccel += axOff;
    yaccel += ayOff;
    zaccel += azOff;
    
    if(xaccel <= axnThresh | xaccel >= axThresh | yaccel <= aynThresh | yaccel >= ayThresh | zaccel <= aznThresh | zaccel >= azThresh)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*//cannot read more than 1 byte at a time...
bool motionDetect(void)
{
    I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_H,6,&data6); //reads all data and stores in data6 array
    xaccel = combineHL(data6[0],data6[1]);
    yaccel = combineHL(data6[2],data6[3]);
    zaccel = combineHL(data6[4],data6[5]);
    
    xaccel += axOff;
    yaccel += ayOff;
    zaccel += azOff;
    
    if(xaccel <= axnThresh | xaccel >= axThresh | yaccel <= aynThresh | yaccel >= ayThresh | zaccel <= aznThresh | zaccel >= azThresh)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/


//from github user jrowberg
//uses I2C to write bytes using the MSSP module on the PIC18F26k22
//@param devAddr    device address should be 0x68 for MPU6050
//@param regAddr    register address you want to write to
//@param length     length of the data you want to write out
//@param data       pointer to the data you want to write out
//@return   true if write is finished and successful
bool I2C1dev_writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data) {
    // S
    IdleI2C1();
    StartI2C1();

    // Device write address
    IdleI2C1();
    WriteI2C1(devAddr << 1 | 0x00);

    // Register address
    IdleI2C1();
    WriteI2C1(regAddr);

    for (i_accel = 0; i_accel < length; i_accel++) {
        // Data byte
        IdleI2C1();
        WriteI2C1(data[i_accel]);
    }
    
    // P
    IdleI2C1();
    StopI2C1();

    return 1;
}

//from github user jrowberg
//uses I2C to read bytes using the MSSP module on the PIC18F26k22
//@param devAddr    device address should be 0x68 for MPU6050
//@param regAddr    register address you want to read from
//@param length     length of the data you want to read
//@param data       pointer to the variable you want the data to be stored to
//@return           count_accel, which should be length - 1
int8_t I2C1dev_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data) {
    count_accel = 0;

    // S
    IdleI2C1();
    StartI2C1();

    // Device write address
    IdleI2C1();
    WriteI2C1(devAddr << 1 | 0x00);

    // Register address
    IdleI2C1();
    WriteI2C1(regAddr);

    // R
    IdleI2C1();
    RestartI2C1();

    // Device read address
    IdleI2C1();
    WriteI2C1(devAddr << 1 | 0x01);

    for (count_accel = 0; count_accel < length; count_accel++) {
        // Data byte
        IdleI2C1();
        data[count_accel] = ReadI2C1();

        if (count_accel == length - 1) {
            // NACK
            IdleI2C1();
            NotAckI2C1();
        } else {
            // ACK
            IdleI2C1();
            AckI2C1();
        }
    }

    // P
    IdleI2C1();
    StopI2C1();

    return count_accel;
}

//v1, there is an i2c v4 version that does not work
//from the i2c.h file in the peripheral library
signed char WriteI2C1( unsigned char data_out )
{
  SSPBUF = data_out;           // write single byte to SSPBUF
  if ( SSPCON1bits.WCOL )      // test if write collision occurred
   return ( -1 );              // if WCOL bit is set return negative #
  else
  {
	if( ((SSPCON1&0x0F)!=0x08) && ((SSPCON1&0x0F)!=0x0B) )	//Slave mode only
	{
	      SSPCON1bits.CKP = 1;        // release clock line 
	      while ( !PIR1bits.SSPIF );  // wait until ninth clock pulse received

	      if ( ( !SSPSTATbits.R_W ) && ( !SSPSTATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
	      {
	        return ( -2 );           //return NACK
	      }
		  else
		  {
			return ( 0 );				//return ACK
		  }	
	}
	else if( ((SSPCON1&0x0F)==0x08) || ((SSPCON1&0x0F)==0x0B) )	//master mode only
	{ 
	    while( SSPSTATbits.BF );   // wait until write cycle is complete   
	    IdleI2C1();                 // ensure module is idle
	    if ( SSPCON2bits.ACKSTAT ) // test for ACK condition received
	    	 return ( -2 );			// return NACK
		else return ( 0 );              //return ACK
	}
	
  }
}

//v1
//from the i2c.h file in the peripheral library
//@TODO add time out!!! gets stuck on while (!SSPSTATbits.BF); occasionally
unsigned char ReadI2C1( void )
{
if( ((SSPCON1&0x0F)==0x08) || ((SSPCON1&0x0F)==0x0B) )	//master mode only
  SSPCON2bits.RCEN = 1;           // enable master for 1 byte reception
  while ( !SSPSTATbits.BF );      // wait until byte received  //ADD TIMEOUTS!!! -Rahul
  return ( SSPBUF );              // return with read byte 
}

//checks if MPU6050 is accessible via I2C by checking the WHO_AM_I register on the MPU6050
//@return returns true if received byte is correct slave address 0x68
bool testConnection(void)
{
    //Single Byte Read
    uint8_t readAddress;
    I2C1dev_readBytes(mpuAddress,WHO_AM_I_REG,1,&readAddress);
    
    if(readAddress == 0x68)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
