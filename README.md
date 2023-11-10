# Smart-Car-Parkinglot
Components Used:
.	Arduino UNO
.	NodeMCU Esp 8266
.	SKG13BL GPS Receiver
.	I.R. Sensors
.	Bread Board
.	16*2 I2C LCD Display
.	Potentiometer
.	Connecting Wires 

About the model:
.	First, the Arduino code was written in Arduino ide and burned in the Arduino. 
.	The connection pins for the LCD, IR sensors and ESP were specified in the code.
.	Another code for interfacing GPS to Node MCU was written and burned in the       Node MCU.
.	In the Node MCU code, pins for connecting GPS were specified.
.	Transfer and receiver pins for communication between Arduino and Node MCU were specified.
.	All the connections were done as specified in the two codes.

Model
.	A model of a parking lot was made with three parking slots and an LCD was placed at the entry of the parking lot.
.	 Two IR sensor were placed at the entrance.
.	Three IR sensors at each of the three lots were placed.
.	The LCD and the IR sensors were connected to the Arduino directly.
.	The GPS is connected to the Node MCU ESP8266.
.	The Node MCU ESP8266 is then connected to the Arduino.
.	The Arduino code read the entry and exit IR sensors values and displayed it to the LCD display and also sent those values to the Node MCU.
.	The Node MCU code read the latitude and longitude values from the GPS and the IR sensor values from the Arduino and sent those values to the database. 
