/*
 *@author Rahul Chidurala
 *@date 4/3/16
 */
#include "accel.h"

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

uint16_t combineHL(uint8_t high, uint8_t low)
{
    return ((high << 8) | low);
}

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


unsigned char ReadI2C1( void )
{
if( ((SSPCON1&0x0F)==0x08) || ((SSPCON1&0x0F)==0x0B) )	//master mode only
  SSPCON2bits.RCEN = 1;           // enable master for 1 byte reception
  while ( !SSPSTATbits.BF );      // wait until byte received  //ADD TIMEOUTS!!! -Rahul
  return ( SSPBUF );              // return with read byte 
}

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
