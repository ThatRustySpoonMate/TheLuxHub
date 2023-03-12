#include <Arduino.h>

#include "main.h"

// Data source section
AnalogDataSource EGTSensor;
LoRaDataSource BatteryVoltage;
LoRaDataSource CurrentSens1;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
}