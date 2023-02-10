//
// Assignment 5 - Question 1 and 2
// 200548559 - Felipe Simoes Cayres
//

// Prototypes



// Variables

  int redLedPin = 13;
  int greenLedPin = 12; //The blue LED is connected pin 13 of the Arduino.

  int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
  int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
  int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.


  int button1Pin = 2; //The SW1 button is connect to pin 2 of the Arduino.
  int button2Pin = 3;

  volatile bool state = true;
  volatile bool state2 = false;

// Setup

void setup() { //The Setup function runs once

  pinMode(greenLedPin, OUTPUT); //Setup blue LED pin as an output pin.
  pinMode(redLedPin, OUTPUT); //Setup button1 pin as an input pin.
  attachInterrupt(digitalPinToInterrupt(button1Pin), clickButton1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button2Pin), clickButton2, CHANGE);
  Serial.begin(9600);
}


			//
			// Level 3  - cycling through three RGB colors
			//

void loop() { //The loop function runs forever.

  while (state == true){
    int data = 500;
    if (state == true) { //Check to see if button1 is pressed.
        // Turn on RED LED
      turnOnLEDByRGB (255,0,0); // red (255, 0, 0);
      delay(data);
      }

    // Turn on Green LED
    if (state == true) {
      turnOnLEDByRGB (0,255,0); // green (0, 255, 0)
      delay(data);
    }

    // Turn on Blue LED
    if (state == true){
      turnOnLEDByRGB (0,0,255); // blue (0, 0, 255)
      delay(data); 
    }
  }

  while (state ==false) {
	turnOffRGBLED();
  }
  
}

	// Functions

void clickButton1() {
	state = true;

}

void clickButton2() {
	state = false;
}



// Turn On led using RGB CODE
void turnOnLEDByRGB (int red, int green, int blue){
  analogWrite(RGBRedPin, red); //Turn on RED
  analogWrite(RGBGreenPin, green); //Turn on GREEN
  analogWrite(RGBBluePin, blue); //Turn on BLUE
}

// Turn off LED
void turnOffRGBLED () {
  analogWrite(RGBRedPin, LOW); //Turn off RED
  analogWrite(RGBBluePin, LOW); //Turn off BLUE
  analogWrite(RGBGreenPin, LOW); //Turn off GREEN
}