
/*
 *@author Rahul Chidurala
 *@date 4/3/16
 */
#include "accel.h"


/**
 * Module variables 
 */

static uint8_t mpuAddress = 0x68;
static int8_t count_accel = 0; //used by I2C readBytes
static int i_accel = 0; //used by I2C writeBytes,calculateOffset

static int axOff = -734;
static int ayOff = 198;
static int azOff = -22798;

static const int axThresh = 1000,
                 ayThresh = 1000,
                 azThresh = 1000; //THRESHOLDS

static const int axnThresh = -1000,
                 aynThresh = -1000,
                 aznThresh = -1000; //negative THRESHOLDS

static int xaccel,
           yaccel,
           zaccel;

uint16_t accel_timeout = 1000;
bool accel_mpu_initialized = false;

bool accel_initialize_MPU()
{
    //Reset disabled, sleep disabled,cycle disabled, temp disabled, clk_sel 000 (internal)
    accel_mpu_initialized &= accel_I2C1dev_writeBytes(mpuAddress,PWR_MGMT_1_REG,1,PWR_MGMT_1_BITS);
    
    //self tests x,y,z off,range +-2000 degrees/s
    accel_mpu_initialized &= accel_I2C1dev_writeBytes(mpuAddress,GYRO_CONFIG_REG,1,GYRO_CONFIG_BITS);
    
    //self tests x,y,z off,range +-16g
    accel_mpu_initialized &= accel_I2C1dev_writeBytes(mpuAddress,ACCEL_CONFIG_REG,1,ACCEL_CONFIG_BITS);
    
    accel_calculate_offset(1000); //calculates offsets
    
    return accel_mpu_initialized;
}

uint16_t accel_combine_HL(uint8_t high, uint8_t low)
{
    return ((high << 8) | low);
}

void accel_calculate_offset(uint16_t samples)
{
    int tempX,tempY,tempZ; //for calculating offsets
    
    xaccel = axOff * (-1);
    yaccel = ayOff * (-1);
    zaccel = azOff * (-1);
    for(i_accel=0; i_accel<samples; i_accel++)
    {
        accel_I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_H,1,&read_8_H); //reads X accel High data and stores in read_8_H
        accel_I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_L,1,&read_8_L);
        tempX = accel_combine_HL(read_8_H,read_8_L);
        xaccel = xaccel/2 + tempX/2;

        accel_I2C1dev_readBytes(mpuAddress,ACCEL_YOUT_H,1,&read_8_H);
        accel_I2C1dev_readBytes(mpuAddress,ACCEL_YOUT_L,1,&read_8_L);
        tempY = accel_combine_HL(read_8_H,read_8_L);
        yaccel = yaccel/2 + tempY/2;
        
        accel_I2C1dev_readBytes(mpuAddress,ACCEL_ZOUT_H,1,&read_8_H);
        accel_I2C1dev_readBytes(mpuAddress,ACCEL_ZOUT_L,1,&read_8_L);
        tempZ = accel_combine_HL(read_8_H,read_8_L);
        zaccel = zaccel/2 + tempZ/2;
    }
    axOff = (-1) * xaccel;
    ayOff = (-1) * yaccel;
    azOff = (-1) * zaccel;
}

bool accel_motion_detect(void)
{
    accel_I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_H,1,&read_8_H); //reads X accel High data and stores in read_8_H
    accel_I2C1dev_readBytes(mpuAddress,ACCEL_XOUT_L,1,&read_8_L);
    xaccel = accel_combine_HL(read_8_H,read_8_L);
    
    accel_I2C1dev_readBytes(mpuAddress,ACCEL_YOUT_H,1,&read_8_H);
    accel_I2C1dev_readBytes(mpuAddress,ACCEL_YOUT_L,1,&read_8_L);
    yaccel = accel_combine_HL(read_8_H,read_8_L);
    
    accel_I2C1dev_readBytes(mpuAddress,ACCEL_ZOUT_H,1,&read_8_H);
    accel_I2C1dev_readBytes(mpuAddress,ACCEL_ZOUT_L,1,&read_8_L);
    zaccel = accel_combine_HL(read_8_H,read_8_L);
    
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

bool accel_I2C1dev_writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data) {
    // S
    IdleI2C1();
    StartI2C1();

    // Device write address
    IdleI2C1();
    accell_write_I2C1(devAddr << 1 | 0x00);

    // Register address
    IdleI2C1();
    accell_write_I2C1(regAddr);

    for (i_accel = 0; i_accel < length; i_accel++) {
        // Data byte
        IdleI2C1();
        accell_write_I2C1(data[i_accel]);
    }
    
    // P
    IdleI2C1();
    StopI2C1();

    return 1;
}

 
int8_t accel_I2C1dev_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data) {
    count_accel = 0;

    // S
    IdleI2C1();
    StartI2C1();

    // Device write address
    IdleI2C1();
    accell_write_I2C1(devAddr << 1 | 0x00);

    // Register address
    IdleI2C1();
    accell_write_I2C1(regAddr);

    // R
    IdleI2C1();
    RestartI2C1();

    // Device read address
    IdleI2C1();
    accell_write_I2C1(devAddr << 1 | 0x01);

    for (count_accel = 0; count_accel < length; count_accel++) {
        // Data byte
        IdleI2C1();
        data[count_accel] = acell_read_I2C1();

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

signed char accell_write_I2C1( unsigned char data_out )
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
	    while( SSPSTATbits.BF);   // wait until write cycle is complete   
	    IdleI2C1();                 // ensure module is idle
	    if ( SSPCON2bits.ACKSTAT ) // test for ACK condition received
	    	 return ( -2 );			// return NACK
		else return ( 0 );              //return ACK
	}
	
  }
}


unsigned char acell_read_I2C1( void )
{
    accel_timeout = 1000;
if( ((SSPCON1&0x0F)==0x08) || ((SSPCON1&0x0F)==0x0B) )	//master mode only
  SSPCON2bits.RCEN = 1;           // enable master for 1 byte reception
  while ( !SSPSTATbits.BF && accel_timeout--);      // wait until byte received  //ADD TIMEOUTS!!! -Rahul
  return ( SSPBUF );              // return with read byte 
}

bool accel_test_connection(void)
{
    //Single Byte Read
    uint8_t readAddress;
    accel_I2C1dev_readBytes(mpuAddress,WHO_AM_I_REG,1,&readAddress);
    
    if(readAddress == 0x68)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
