#include <Arduino.h>

#include "main.h"

// Data source section
AnalogDataSource EGTSensor;
LoRaDataSource StarterVoltage;
LoRaDataSource CurrentSens1;

// Create Widget for each Data Source

// Create Page and apply above widgets to the pages

// Create dashboard to display the pages



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
}