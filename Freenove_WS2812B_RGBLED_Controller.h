// Freenove_WS2812B_RGBLED_Controller.h
/**
 * Brief	Apply to Freenove WS2812B RGBLED Controller. 
 *			You can use I2C or UART to communicate.
 * Author	SuhaylZhao
 * Company	Freenove
 * Date		2019-7-20
 */

#ifndef _FREENOVE_WS2812B_RGBLED_CONTROLLER_h
#define _FREENOVE_WS2812B_RGBLED_CONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
//#include <SoftwareSerial.h>


#define REG_LEDS_COUNTS					0
#define REG_SET_LED_COLOR_DATA			1
#define REG_SET_LED_COLOR				2
#define REG_SET_ALL_LEDS_COLOR_DATA		3
#define REG_SET_ALL_LEDS_COLOR			4
#define REG_TRANS_DATA_TO_LED			5

#define REG_READ_I2C_ADDRESS			251
#define REG_GET_UART_BAUDRATE			251

#define REG_SET_UART_BAUDRATE			252
#define REG_SET_I2C_ADDRESS				253

#define REG_GET_BRAND					254
#define REG_GET_FIRMWARE_VERSION		255

#define I2C_COMMUNICATION_MODE			0
#define UART_COMMUNICATION_MODE			1

#define STRING_BRAND_LENGTH				9
#define STRING_VERSION_LENGTH			16

#define SECTET_KEY_A					0xaa
#define SECTET_KEY_B					0xbb
#define UART_START_BYTE					0xcc
#define UART_END_BYTE					0xdd
#define UART_ACK_BYTE					0x06

const u32 _BAUDRATE[] = { 115200, 1200, 2400, 4800, 9600, 14400, 19200, 38400, 57600, 115200, 128000, 230400, 500000 };

class Freenove_WS2812B_Controller
{
private:
	u8 I2C_Address;
	u8 uartBaudrateIndex;
	u8 commMode;
	u16 ledCounts;
	u32 uartWaitAckTime;	//unit: us
	HardwareSerial *_serial;
	//HardwareSerial *hdSerial;
	//SoftwareSerial *swSerial;
	int writeRegOneByte(uint8_t val);
	int writeReg(uint8_t cmd, u8 *value, u8 size_a);
	int readReg(uint8_t cmd, char *recv, u16 count);
	//bool i2cWriteDataToController(u8 cmd, u8 *value, u8 size_a);
	bool uartWriteDataToControllerWithAck(u8 param[5], bool isShowLed = false);
public:
	Freenove_WS2812B_Controller(u8 _address = 0x20, u16 n = 8);
	Freenove_WS2812B_Controller(HardwareSerial *serial_param, u32 _baudrate = 115200, u16 n = 8);
	//Freenove_WS2812B_Controller(SoftwareSerial *serial_param, u32 _baudrate = 115200, u16 n = 8);

	bool begin();
	bool setLedCount(u16 n);

	bool setLedColorData(u8 index, u32 rgb);
	bool setLedColorData(u8 index, u8 r, u8 g, u8 b);

	bool setLedColor(u8 index, u32 rgb);
	bool setLedColor(u8 index, u8 r, u8 g, u8 b);

	bool setAllLedsColorData(u32 rgb);
	bool setAllLedsColorData(u8 r, u8 g, u8 b);

	bool setAllLedsColor(u32 rgb);
	bool setAllLedsColor(u8 r, u8 g, u8 b);

	bool show();

	u8 getI2CAddress();
	u32 getUartBaudrate();
	bool setUartBaudrate(u32 _baudrate);
	bool setI2CNewAddress(u8 addr);
	String getBrand();
	String getFirmwareVersion();

	uint32_t Wheel(byte pos); 
};

#endif

