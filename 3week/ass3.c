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
  data = 1023 - analogRead(rotationPin); 
  
  Serial.print("Rotation value =");
  Serial.println(data); //Print the data to the serial port.
  
  if (data ==0) data = 1; // Faster time visible on LED
  if (data ==1023) return;  // rotationPin turned off
  
  // three colors blinking
  redColor(data);
  greenColor(data);
  blueColor(data);  
  
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
  	displayColorLED (255,0,0); // red (255, 0, 0)
  } 
  else if (data <= 340 ){
  	displayColorLED (255,165,0); // orange (255, 165, 0)
  } 
  else if (data <= 510){
  	displayColorLED (255,255,0); // yellow (255, 255, 0)
  } 
  else if (data <= 680){
  	displayColorLED (0,255,0); // green (0, 255, 0)
  } 
  else if (data <= 850){
  	displayColorLED (0,0,255); // blue (0, 0, 255)
  } 
  else if (data <=1023){
  	displayColorLED (128,0,128); // purple (128, 0, 128)
  }
}

*/

	//
	// Level 4 - cycle through rainbow colours
	//

/*

// Setup

  // Variables level 4
  
	String LEDLightsOrder = "";
	unsigned long delay1 = 0;

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
  int data = 1023 - analogRead(rotationPin); // Get value of potentiometer
    if (data == 0){ 
    	data = 1;  // Way to set fastest visible LED blink
    } else if (data == 1023){
    	data =0;	// Way to set LED turned off (not visible) 
    }
  
  char character;
  
	if (Serial.available()) {
		//Read typed characters 
		character = Serial.read();
    	//Add characters inputed by user
		LEDLightsOrder += character;
    	//Type to type and read:
		delay1 = millis();
  		}
  	// Condition to delay time and wait imput from the user(input not empty)

  	if (((millis() - delay1) > 10) && (LEDLightsOrder != "")) {    

		for (int i = 0; i<3; i++){
			if (LEDLightsOrder[i] == 'r') {
				redColor(data);
	    	} else if (LEDLightsOrder[i] == 'g'){
    	  		greenColor(data);
      		} else if (LEDLightsOrder[i] == 'b') {
	      		blueColor(data); 
    	    }
      
				// Printing colors sequence and rotation on terminal
			if (i==2) {
          		Serial.print("Colors sequence: ");
				Serial.println(LEDLightsOrder); 
          
          		Serial.print("Rotation value =");
				Serial.println(data); //Print the data to the serial port.

			}
  		}
    }
}

*/

	// Extra challenge

// Setup

	String LEDLightsOrder = "";
	unsigned long delay1 = 0;

void setup() { //The Setup function runs once.

  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.

  Serial.begin(9600); //Send data to the Serial monitor.
  pinMode(rotationPin,INPUT); //Setup rotationPin as an input.
  
  Serial.println("Type  the RGB order to blink lights");
  Serial.println("Choose and type 7 letters and your options are:\n R to Red   ||   G to Green  ||  B to Blue\n C to Cyan  ||  M to Magenta ||  Y to Yellow\n W to White ||");
  
} 


void loop() {
  int data = 1023 - analogRead(rotationPin); // Get value of potentiometer
    if (data == 0){ 
    	data = 1;  // Way to set fastest visible LED blink
    } else if (data == 1023){
    	data =0;	// Way to set LED turned off (not visible) 
    }
  
  char character;
  
	if (Serial.available()) {
		//Read typed characters 
		character = Serial.read();
		LEDLightsOrder += character;

    	//Add characters inputed by user
		
    	//Type to type and read:
		delay1 = millis();
  		}
  	// Condition to delay time and wait imput from the user(input not empty)

  	if (((millis() - delay1) > 10) && (LEDLightsOrder != "")) {    

		for (int i = 0; i<3; i++){
			if (LEDLightsOrder[i] == 'r') {
				redColor(data);
	    	} else if (LEDLightsOrder[i] == 'g'){
    	  		greenColor(data);
      		} else if (LEDLightsOrder[i] == 'b') {
	      		blueColor(data); 
    	    }
      
				// Printing colors sequence and rotation on terminal
			if (i==2) {
          		Serial.print("Colors sequence: ");
				Serial.println(LEDLightsOrder); 
          
          		Serial.print("Rotation value =");
				Serial.println(data); //Print the data to the serial port.

			}
  		}
    }
}




		// Functions

  //Display Red color (255, 0, 0)
void redColor (float time){
  analogWrite(RGBRedPin, 255); //Turn on RED
  delay(time); //Set time delay 
  analogWrite(RGBRedPin, 0); //Turn off RED

}

  //Display Green color (0, 255, 0)
void greenColor(float time) {
  analogWrite(RGBGreenPin, 255); //Turn on GREEN
  delay(time); //Set time delay 
  analogWrite(RGBGreenPin, 0); //Turn off GREEN
}
  
  //Display Blue Color (0, 0, 255)
void blueColor (float time){

  analogWrite(RGBBluePin, 255); //Turn on BLUE
  delay(time); //Set time delay 
  analogWrite(RGBBluePin, 0); //Turn off BLUE
}
  
  //Display RGB color (red, green, blue)
void displayColorLED (int red, int green, int blue){
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
