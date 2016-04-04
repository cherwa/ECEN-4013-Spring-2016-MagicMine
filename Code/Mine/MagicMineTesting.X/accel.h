/*
 *@author Rahul Chidurala
 *@date 4/3/16
 */

#include "mcc_generated_files/mcc.h"
//defining registers of accelerometer
#define WHO_AM_I_REG 0x75
#define GYRO_CONFIG_REG 0x1B
static uint8_t GYRO_CONFIG_BITS = 0b00011000; //+-2000 degrees/s
#define ACCEL_CONFIG_REG 0x1C
static uint8_t ACCEL_CONFIG_BITS = 0b00011000; //+-16g
#define MOT_THR_REG 0x1F
static uint8_t MOT_THR_BITS = 0x2;
#define INT_ENABLE_REG 0x38
static uint8_t INT_ENABLE_BITS = 0b01000000;
#define PWR_MGMT_1_REG 0x6B
static uint8_t PWR_MGMT_1_BITS = 0b00001000; //temp = 1 means disable temp
#define USER_CTRL_REG 0x6A
static uint8_t USER_CTRL_BITS = 0b00000000;
#define INT_STATUS 0x3A
static uint8_t MOT_INT_FLAG_MASK = 0b01000000;
#define SLAVE_I2C_GENERIC_RETRY_MAX     100

#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40


//from plib/i2c.h (was hidden)
#define StartI2C1()  SSP1CON2bits.SEN=1;while(SSP1CON2bits.SEN)
#define IdleI2C1()    while ((SSP1CON2 & 0x1F) | (SSP1STATbits.R_W))
#define RestartI2C1()  SSP1CON2bits.RSEN=1;while(SSP1CON2bits.RSEN)
#define NotAckI2C1()     SSP1CON2bits.ACKDT=1, SSP1CON2bits.ACKEN=1;while(SSP1CON2bits.ACKEN)
#define AckI2C1()        SSP1CON2bits.ACKDT=0, SSP1CON2bits.ACKEN=1;while(SSP1CON2bits.ACKEN)
#define StopI2C1()  SSP1CON2bits.PEN=1;while(SSP1CON2bits.PEN)

//function prototypes
bool initializeMPU(void);
int8_t I2C1dev_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data);
bool I2C1dev_writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data);
signed char WriteI2C1( unsigned char data_out);
unsigned char ReadI2C1( void );
bool motionDetect(void);
uint16_t combineHL(uint8_t high, uint8_t low);
void calculateOffset(uint16_t samples);
bool testConnection(void);

//global variables
uint8_t mpuAddress = 0x68;
int8_t count_accel = 0; //used by I2C readBytes
int i_accel = 0; //used by I2C writeBytes,calculateOffset

uint16_t read_16;
uint8_t read_8_H,read_8_L;
bool initializeSuccess = true;
uint8_t readData;
int axOff = -734;
int ayOff = 198;
int azOff = -22798;
const int axThresh=1000,ayThresh=1000,azThresh=1000; //THRESHOLDS
const int axnThresh=-1000,aynThresh=-1000,aznThresh=-1000; //negative THRESHOLDS

int xaccel,yaccel,zaccel;
bool motionDetected = 0;