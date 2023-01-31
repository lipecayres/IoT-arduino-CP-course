//
// 200548559 - Felipe Simoes Cayres
// Date: 
// Description:  Assignment 4 - COMP 1045
//

//Variables
	
  int photoResistorPin = A1; //Photoresistor sensor plugged into pin A0
  int RGBRedPin = 12; //The red RGB LED is connected pin 12 of the Arduino.
  int RGBGreenPin = 8; //The green RGB LED is connected pin 8 of the Arduino.
  int RGBBluePin = 13; //The blue RGB LED is connected pin 13 of the Arduino.
  int RGBYellowPin = 7; //The blue RGB LED is connected pin 7 of the Arduino.
  int binaryNumber;     // Variable to store binary number

  	//
	// Level 1 - Convert number into a binary number and print at screen 
	//


void setup() { //The Setup function runs once.

  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.

  pinMode(photoResistorPin,INPUT); //Setup rotationPin as an input.

  Serial.begin(9600); //Send data to the Serial monitor.
}