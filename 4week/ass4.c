//
// 200548559 - Felipe Simoes Cayres
// Date: 
// Description:  Assignment 4 - COMP 1045
//

// Variables

  int photoresistorInput = A1;
  int data = 0;

  int RGBRedPin = 12; 							//The red RGB LED is connected pin 12 of the Arduino.
  int RGBGreenPin = 8; 							//The green RGB LED is connected pin 8 of the Arduino.
  int RGBBluePin = 13; 							//The blue RGB LED is connected pin 13 of the Arduino.
  int RGBYellowPin = 7; 						//The blue RGB LED is connected pin 7 of the Arduino.


		// Functions


  
// Turn on Red LED
void redLED () {
  digitalWrite(RGBRedPin, HIGH); 
  digitalWrite(RGBBluePin, LOW); 
  digitalWrite(RGBGreenPin, LOW);
}

// Turn on Green LED
void greenLED () {
  digitalWrite(RGBRedPin, LOW); 
  digitalWrite(RGBBluePin, LOW); 
  digitalWrite(RGBGreenPin, HIGH); 
}

