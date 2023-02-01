//
// 200548559 - Felipe Simoes Cayres
// Date: 
// Description:  Assignment 4 - COMP 1045
//

// Prototypes

  void redLED (); 								// Turn on Red LED
  void greenLED();								// Turn on Green LED
  void blueLED ();								// Turn on Blue LED
  void allLED (); 								// Turn on all LED
  void turnOffLED (); 							// Turn off all LED
  void turnOnYellowLED ();						// Turn on Yellow LED
  void turnOffYellowLED ();						// Turn off yellow LED



// Variables

  int photoresistorInput = A1;
  int data = 0;

  int RGBRedPin = 12; 							//The red RGB LED is connected pin 12 of the Arduino.
  int RGBGreenPin = 8; 							//The green RGB LED is connected pin 8 of the Arduino.
  int RGBBluePin = 13; 							//The blue RGB LED is connected pin 13 of the Arduino.
  int RGBYellowPin = 7; 						//The blue RGB LED is connected pin 7 of the Arduino.


// Setup

void setup() {
  
  pinMode(photoresistorInput, INPUT);
  pinMode(RGBRedPin, OUTPUT); 					//Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); 				//Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); 					//Setup blue RGB LED pin as an output pin.
  pinMode(RGBYellowPin, OUTPUT); 				//Setup blue RGB LED pin as an output pin.

  Serial.begin(9600);
}

			//
			// Challenge 1  - Convert into a binary number and display on screen
			//


void loop(){	

  // Converting to binary inverted

  data = analogRead(photoresistorInput);		// Get data from photoresistor
  Serial.print("Light Sensor: ");   			// Display photoresistor input on screen
  Serial.println(data);

  // Variables to converting binary number

  int numberToDivide = data;					// Variable created to do not change the value of data when finding the binary number; 
  int moduleBy2 = numberToDivide;  				// This variable save the module divided by 2
  int floorBy2 = 1;  							// This variable gets the floor divided by 2 - Starts in 1 to don't break the loop while;
  String binaryInverted = "";  					// Gets the binary number in a inverted position
  String binaryReal = "";  						// Binary number at correct order

  // Converting photosensor input to binary inverted

  while(floorBy2 >0){							// Condition to stop division to get binary number
    moduleBy2 = numberToDivide % 2;  			// Module operation using input from photosensor 
    floorBy2 = numberToDivide /2;				// Floor operation (truncated) using input from photosensor
    binaryInverted += moduleBy2;				// Saving module number in a string variable
    numberToDivide = floorBy2;					// Set new value to data to find binary number (floorBy2)
  }

  // Getting binary real using binary inverted

  int n=binaryInverted.length();				// Saving the real binary lenght  in a variable
  for(int i = n-1; i >= 0; i--){				// Setting loop to reverse iteration
    binaryReal += binaryInverted[i];			// Getting binary real number saving by reverse iteraction on binary inverted
  }  

  // Display binary on screen

  Serial.print("Binary number: ");				// Print binary number at screen
  Serial.println(binaryReal);					// Display the binary number on screen




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

// Turn on Blue LED
void blueLED () {
  digitalWrite(RGBRedPin, LOW); 
  digitalWrite(RGBBluePin, HIGH); 
  digitalWrite(RGBGreenPin, LOW); 
}

// Turn on reg, green and blue LED
void turnOnRGBLED () {
  digitalWrite(RGBRedPin, HIGH); 
  digitalWrite(RGBBluePin, HIGH);
  digitalWrite(RGBGreenPin, HIGH); 
}

// Turn off reg, green and blue LED
void turnOffRGBLED () {
  digitalWrite(RGBRedPin, LOW); 
  digitalWrite(RGBBluePin, LOW); 
  digitalWrite(RGBGreenPin, LOW); 
}

// Turn on Yellow LED
void turnOnYellowLED () {
  digitalWrite(RGBYellowPin, HIGH); 
}

// Turn off Yellow LED
void turnOffYellowLED () {
  digitalWrite(RGBYellowPin, HIGH); 
}
