  /**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
**/
#include "String.h"

// TODO: Add support for NRF24L01+ and other wireless modules

/** Define connected peripherals --------------------------------------------------- **/
#define LORA_MODULE 0 // 0 = Disabled, 1 = SX1276
#define DISPLAY 0 // 0 = Disabled, 1 = 
#define ADC 1 // 0 = Disabled, 1 = Internal, 2 = ADS1115

// Peripheral Config
#if DISPLAY == 0
    #define NUM_PAGES 0 // Number of pages to cycle through
    #define MAX_ITEMS_ON_PAGE 0 // Number of items on each page
    #define FIT_TWO_WIDE 0 // 0 = Disabled, 1 = Enabled
#else if DISPLAY == 1
    #define NUM_PAGES 8 // Number of pages to cycle through
    #define MAX_ITEMS_ON_PAGE 1 // Number of items on each page
    #define FIT_TWO_WIDE 0 // 0 = Disabled, 1 = Enabled
#endif 


#if ADC == 0

#else if ADC == 1
    #define NUM_ADC_CHANNELS 1 // Number of ADC channels to read
    #define ADC_SDA 21 // SDA pin for the ADC
    #define ADC_SCL 22 // SCL pin for the ADC
    #define ADC_ADDR 0x48 // I2C address of the ADC
#endif


/** Define pins --------------------------------------------------- **/
#if LORA_MODULE == 1
    #define LORA_CS_PIN 18 // Chip select
    #define LORA_RST_PIN 14 // Reset pin
    #define LORA_IRQ_PIN 26 // IRQ(Interrupt Request)
    #define LORA_FREQUENCY 915E6 // This may not be used
#endif

#define UserButton 38 // Button on the board that is used to cycle through pages

/** Define struct --------------------------------------------------- **/
struct WirelessDataSource {
  uint8_t packetID;         // ID of the Wireless packet to look for
  uint32_t pollFreq;  // Frequency to update this data source -- Likely not used and will be placed in widget instead
};

struct LoRaDataSource{
  uint8_t packetID;         // ID of the LORA packet to look for
  uint32_t pollFreq;  // Frequency to update this data source -- Likely not used and will be placed in widget instead
};

struct AnalogDataSource{
  uint8_t pin;      // Analog pin
};

union SourceType { // Union of all possible data sources
  WirelessDataSource wireless;
  LoRaDataSource lora;
  AnalogDataSource analog;
};

struct DataSource {
  SourceType type; // Type of data source
  uint8_t data[8]; // Most recent data
};

struct UIWidget {
  uint8_t widgetID;      // Order of creation, starts at 0
  DataSource dataSrc;    // Source of data for this widget
  uint8_t widgetData[8]; // Currently displayed data
};

struct UIPage {
    uint8_t pageID;                         // Order of creation, starts at 0
    uint8_t widgetCountCurrent;             // Number of widgets on this page
    uint8_t widgetCountTotal = MAX_ITEMS_ON_PAGE; // Maximum Number of widgets on this page
    #if FIT_TWO_WIDE == 1
      uint8_t widgetCountHeight = MAX_ITEMS_ON_PAGE / 2;          // Number of widgets that can fit on this page
    #else
      uint8_t widgetCountHeight = MAX_ITEMS_ON_PAGE;          // Number of widgets that can fit on this page
    #endif
    UIWidget widgets[MAX_ITEMS_ON_PAGE];        // Widgets on this page, if 
};

struct Dashboard {
    uint8_t pageCount;          // Total number of pages
    uint8_t currentPage = 0;    // Current page -- index of the pages array
    UIPage pages[NUM_PAGES];    // Pages

};
