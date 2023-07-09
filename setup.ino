#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>

// Constants for data logging shield
#define SD_CHIP_SELECT 10

// Constants for LCD screen
#define LCD_ADDRESS 0x27
#define LCD_ROWS 4
#define LCD_COLS 20

// Constants for sound sensor
#define SOUND_SENSOR_PIN A0

// Constants for data logging interval
#define LOGGING_INTERVAL 300000 // 5 minutes in milliseconds

// Variables
unsigned long lastLoggingTime = 0;
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);
File dataFile;
