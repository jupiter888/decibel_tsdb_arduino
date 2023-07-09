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

void setup() {
  // Initialize LCD screen
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.print("Decibel Level:");

  // Initialize data logging shield
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial connection
  }

  if (!SD.begin(SD_CHIP_SELECT)) {
    lcd.clear();
    lcd.print("Error: SD card");
    while (true) {
      ; // Handle SD card error
    }
  }

  dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (!dataFile) {
    lcd.clear();
    lcd.print("Error: Data file");
    while (true) {
      ; // Handle data file error
    }
  }

  // Initialize sound sensor
  pinMode(SOUND_SENSOR_PIN, INPUT);
}
