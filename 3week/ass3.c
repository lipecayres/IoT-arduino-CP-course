//
// Assignment 3
// 200548559 - Felipe Simoes Cayres
// Date:
// Description:
//

//Variables

int rotationPin = A0; //Rotation sensor plugged into pin A0
int data=0; //Used to store data from sensor.

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.

	//
	// Level 1 - Source Code
	//

/*

// Setup

void setup() { //The Setup function runs once.

  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.

  Serial.begin(9600); //Send data to the Serial monitor.
  pinMode(rotationPin,INPUT); //Setup rotationPin as an input.
  
} 

void loop() { //The loop function runs forever.
	
    //Read value from light sensor and store it in the light Data variable.
	data = analogRead(rotationPin); 
	
	Serial.print("Rotation value =");
	Serial.println(data); //Print the data to the serial port.
	delay(1000); //Wait 1 second (1000mS) before running again.
}

*/