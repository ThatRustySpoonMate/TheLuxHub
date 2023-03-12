An Open-source dash software that runs on an Arduino/ESP32 (as the master board) and integrates with sensors placed throughout the car to display the collected sensor data on a display.

The main motivator of this project is so that I don't have to drill holes and run sensor cables throughout the ol' Hilux. Of course this will be an option, however there are multiple wireless transfer methods that can be used. 


Supported methods of data transfer:
 - LoRa (SX1276)
 - Analog input
 - NRF24L01+

Support displays:
 - I need to buy some

Supported master boards:
 - Arduino Uno
 - ESP32-based (Untested)


The node devices are any boards that collect sensor data and relay it to the master. Examples can be ESP32 based boards like the TTGO Tbeam, or ATMEL based Arduino boards like the Arduino Nano or even the UNO.


Example uses:
RTD sensor plumbed into downpipe wired directly to Master board as an EGT

Temperature/Humidity (e.g. DHT22) Sensors monitoring battery temp, engine bay temp etc.. all feeding into an Arduino node that relays the data back to the master via LoRa/Wireless. 

Multiple current sensors residing with the Aux battery setup monitoring the current of lighting/MPPT/cooling/etc... circuits. These current sensors could be connected to an ADS1115 which is in-turn, connected to a node board that relays the data back to the master via LoRa/Wireless

All of these data sources will then be collected and processed by the Master board and displayed onto the connected display. 

  