/*
 *@author Rahul Chidurala
 *@date 4/3/16
 */

#include "mcc_generated_files/mcc.h"

// accelerometer register definitions

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

//global variables
uint16_t read_16;

uint8_t read_8_H,read_8_L;

extern bool accel_mpu_initialized;

uint8_t readData;

bool motionDetected = false; /**< Set to true if motion is detected.*/

extern uint16_t accel_timeout;

/**
 * from plib/i2c.h (was hidden; got that son of gun out of there)
 */
#define StartI2C1()  SSP1CON2bits.SEN=1; while(SSP1CON2bits.SEN)
#define IdleI2C1()    while ((SSP1CON2 & 0x1F) | (SSP1STATbits.R_W))
#define RestartI2C1()  SSP1CON2bits.RSEN=1; while(SSP1CON2bits.RSEN)
#define NotAckI2C1()     SSP1CON2bits.ACKDT=1, SSP1CON2bits.ACKEN=1; while(SSP1CON2bits.ACKEN)
#define AckI2C1()        SSP1CON2bits.ACKDT=0, SSP1CON2bits.ACKEN=1; while(SSP1CON2bits.ACKEN)
#define StopI2C1()  SSP1CON2bits.PEN=1; while(SSP1CON2bits.PEN)

/**
 * EXPECTING MSSP1/i2c1 module!!!
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

//function prototypes

/**
 * Sets up the registers on the MPU6050 in order to read raw x,y,z accelerometer values
 * @return   true if initialization is successful
 */
bool accel_initialize_MPU(void);

/**
 * @author jrowberg github user
 * uses I2C to read bytes using the MSSP module on the PIC18F26k22
 * @param devAddr    device address should be 0x68 for MPU6050
 * @param regAddr    register address you want to read from
 * @param length     length of the data you want to read
 * @param data       pointer to the variable you want the data to be stored to
 * @return           count_accel, which should be length - 1
 */
int8_t accel_I2C1dev_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data);


/**
 * @author jrowberg github user
 * uses I2C to write bytes using the MSSP module on the PIC18F26k22
 * @param devAddr    device address should be 0x68 for MPU6050
 * @param regAddr    register address you want to write to
 * @param length     length of the data you want to write out
 * @param data       pointer to the data you want to write out
 * @return   true if write is finished and successful
 */
bool accel_I2C1dev_writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data);



/**
 * v1, there is an i2c v4 version that does not work
 * the i2c.h file in the peripheral library
 * @author MicroChip
 * @param data_out      data to send
 * @return signed char  -1 means collision, -2 means NACK, 0 means ACK
 */
signed char accell_write_I2C1( unsigned char data_out);


/**
 * v1 from the i2c.h file in the peripheral library
 * @TODO add time out!!! gets stuck on while (!SSPSTATbits.BF); occasionally
 * @TODO add timeout to the while loop, hangs forever if I2C fails
 * @return  byte read from I2C device
 */
unsigned char acell_read_I2C1( void );

/**
 * compares current accelerometer values (with offset) and returns true if values exceed thresholds
 *call this every 200 ms or so
 *@param void
 *@return   true if motion was detected
 */
bool accel_motion_detect(void);

/**
 * combines high and low 8 bit number from _H and _L registers into one 16 bit unsigned number
 * @param high   high byte
 *@param low    low byte
 *@return 16 bit unsigned number combined high and low byte
 */
uint16_t accel_combine_HL(uint8_t high, uint8_t low);

/**
 * takes the defined amount of samples and calculates the proper offsets in the given position
 *example usage:    calculateOffset(1000);
 *@param samples    the number of samples you want to average for calculating the offset, recommended value = 1000
 *@return void
 */
void accel_calculate_offset(uint16_t samples);


/**
 * checks if MPU6050 is accessible via I2C by checking the WHO_AM_I register on the MPU6050 
 * @return returns true if received byte is correct slave address 0x68 
 */
bool accel_test_connection(void);