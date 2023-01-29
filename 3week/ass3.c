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

	// Level 4 and Extra challenge
String LEDLightsOrder = "";  // Sequence from the user
unsigned long delay1 = 0;	   // Delay to input sequence
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

	//
	// Level 2 - Color speed controlled by Rotation dial A0
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
	
  // Read the value from the light sensor 
  // and store it in the lightData variable.
  // Inverted counter (Start slower and become fast).
  data = getPotentiometerInput();
  
  Serial.print("Rotation value =");
  Serial.println(data); //Print the data to the serial port.
  
  // Turn on RED LED
  turnOnLEDByRGB (255,0,0); // red (255, 0, 0);
  delay(data);

  // Turn on Green LED
  turnOnLEDByRGB (0,255,0); // green (0, 255, 0)
  delay(data);

  // Turn on Blue LED
  turnOnLEDByRGB (0,0,255); // blue (0, 0, 255)
  delay(data);

}

*/

	
	//
	// Level 3 - cycle through rainbow colours
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


void loop(){
  
  int data = analogRead(rotationPin); 
  Serial.print("Rotation value =");
  Serial.println(data); //Print the data to the serial port.
  
  	// Conditions to cycle through rainbow colours (ROYGBP)
  if (data == 0){ 
    turnOffLED();  // rotationPin turned off
  }
  else if (data <= 170){  
  	turnOnLEDByRGB (255,0,0); // red (255, 0, 0)
  } 
  else if (data <= 340 ){
  	turnOnLEDByRGB (255,165,0); // orange (255, 165, 0)
  } 
  else if (data <= 510){
  	turnOnLEDByRGB (255,255,0); // yellow (255, 255, 0)
  } 
  else if (data <= 680){
  	turnOnLEDByRGB (0,255,0); // green (0, 255, 0)
  } 
  else if (data <= 850){
  	turnOnLEDByRGB (0,0,255); // blue (0, 0, 255)
  } 
  else if (data <=1023){
  	turnOnLEDByRGB (128,0,128); // purple (128, 0, 128)
  }
}

*/

	//
	// Level 4 - input a pattern of colours using R, G or B
	//
  
/*

// Setup

void setup() { //The Setup function runs once.

  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.

  Serial.begin(9600); //Send data to the Serial monitor.
  pinMode(rotationPin,INPUT); //Setup rotationPin as an input.
  
  Serial.println("Type  the RGB order to blink lights");
  Serial.println("Choose and type 3 letters and your options are:\n R to Red\n G to Green\n B to Blue\n");
  
} 


void loop() {

  int data = getPotentiometerInput(); // Getting potentiometer data

  char character;

  if (Serial.available()) {
    //Read typed characters 
    character = Serial.read();
    //Add characters inputed by user
    LEDLightsOrder += character;
    LEDLightsOrder.toLowerCase();
    //Delay to get user entry
    delay1 = millis();
  }

  // Condition to delay time and wait imput from the user(input not empty)

  if (((millis() - delay1) > 10) && (LEDLightsOrder != "")) {    

    for (int i=0, n=LEDLightsOrder.length(); i<n; i++){ 
      // Turn on LED using letters inputed from user
      turnOnLEDByKey(LEDLightsOrder[i]);
    }

    // Printing colors sequence and rotation on terminal
    Serial.print("Colors sequence: ");
    Serial.println(LEDLightsOrder); 

    Serial.print("Rotation value =");
    Serial.println(data); //Print the data to the serial port.

  }
}

*/

	//
	// Extra challenge - Add other colours to the choices
	//

/*

// Setup


void setup() { //The Setup function runs once.

  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.

  Serial.begin(9600); //Send data to the Serial monitor.
  pinMode(rotationPin,INPUT); //Setup rotationPin as an input.

  // Message to user: How to use the system
  Serial.println("Type  the RGB order to blink lights");
  Serial.println("Choose and type 7 letters and your options are:\n R to Red   ||   G to Green  ||  B to Blue\n C to Cyan  ||  M to Magenta ||  Y to Yellow\n W to White ||");

} 


void loop() {

  data = getPotentiometerInput(); // Getting potentiometer data

  char character;

  if (Serial.available()) {
    //Read typed characters 
    character = Serial.read();

    //Add characters inputed by user
    LEDLightsOrder += character;

    //Delay to get user entry
    delay1 = millis();
  }
  
  // Condition to delay time and wait imput from the user(input not empty)
  if (((millis() - delay1) > 10) && (LEDLightsOrder != "")) {    

    // Setting colors getted at user entry.
    if (validateEntry(LEDLightsOrder)){
      
      // Reading letter to letter the word interted 
      for (int i = 0, n=LEDLightsOrder.length(); i<n; i++){ 
		// Turn on LED using letters inputed from user
        turnOnLEDByKey(LEDLightsOrder[i]);
      }

      // Printing colors sequence and rotation on terminal
        Serial.print("Colors sequence: ");
        Serial.println(LEDLightsOrder); 

        Serial.print("Rotation value =");
        Serial.println(data); //Print the data to the serial port.
    }
  }}

*/


		// Functions 

bool validateEntry(String color) {
  LEDLightsOrder.toLowerCase();
  for (int i = 0, n=LEDLightsOrder.length(); i<n; i++){
    if (LEDLightsOrder[i] == 'r' || 
        LEDLightsOrder[i] == 'g' ||
        LEDLightsOrder[i] == 'b' ||
        LEDLightsOrder[i] == 'c' ||
        LEDLightsOrder[i] == 'w' ||
        LEDLightsOrder[i] == 'm' ||
        LEDLightsOrder[i] == 'y' ) {
      return true;
    } else {
      return false;
    }
  }}

// Turn On led using KEY LETTER
void turnOnLEDByKey (char color) {

  int data = getPotentiometerInput(); // Getting potentiometer data;

  switch(color) { // Selecting colors to display 
    case 'r':  // Red color
      turnOnLEDByRGB(255,0,0);
      delay(data);
      turnOnLEDByRGB(0,0,0);
      break;
    case 'g': // Green color
      turnOnLEDByRGB(0,255,0);
      delay(data);
      turnOnLEDByRGB(0,0,0);
      break;
    case 'b':  // Blue color
      turnOnLEDByRGB(0,0,255);
      delay(data);
      turnOnLEDByRGB(0,0,0);
      break;
    case 'c':  // cyan color
      turnOnLEDByRGB(0,100,100);
      delay(data);
      turnOnLEDByRGB(0,0,0);
      break;
    case 'm':  // magenta color
      turnOnLEDByRGB(255,0,255);
      delay(data);
      turnOnLEDByRGB(0,0,0);
      break;
    case 'y':  // yellow color
      turnOnLEDByRGB(255,255,0);
      delay(data);
      turnOnLEDByRGB(0,0,0);
      break;
    case 'w':  // white color
      turnOnLEDByRGB(255,255,255);
      delay(data);
      turnOnLEDByRGB(0,0,0);
      break;
  }}

// Getting input from potentiometer 
int getPotentiometerInput() {  
  int data = 1023 - analogRead(rotationPin); // Get value of potentiometer
  if (data == 0){ 
    data = 1;  // Way to set fastest visible LED blink
  } else if (data == 1023){
    data =0;	// Way to set LED turned off (not visible) 
  }
  return data;
}  
 

// Turn On led using RGB CODE
void turnOnLEDByRGB (int red, int green, int blue){
  analogWrite(RGBRedPin, red); //Turn on RED
  analogWrite(RGBGreenPin, green); //Turn on GREEN
  analogWrite(RGBBluePin, blue); //Turn on BLUE
}

// Turn off LED
void turnOffLED () {
  analogWrite(RGBRedPin, LOW); //Turn off RED
  analogWrite(RGBBluePin, LOW); //Turn off BLUE
  analogWrite(RGBGreenPin, LOW); //Turn off GREEN
}