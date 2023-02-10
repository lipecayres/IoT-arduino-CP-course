//
// Assignment 5 - Level 3 and 4
// 200548559 - Felipe Simoes Cayres
//

// Prototypes

  void turnOffRGBLED ();  								// Turn off RGB LED
  void turnOnLEDByRGB (int red, int green, int blue);  	// Turn On led using RGB CODE

  void ciclyngRGBColors(int data);  					// Turn On ciclying colors on RGB LED  
  void redLedON(); 										// Turn on Red LED
  void greenLedON(); 									// Turn on Green LED

  void clickButton1();  								// Change button 1 state
  void clickButton2(); 									// Change button 2 state

  void level3ClickButton1(); 							// Change state to true
  void level3ClickButton2(); 							// Change state to false


// Variables

  int redLedPin = 13; 									//The red LED is connected pin 13 of the Arduino.
  int greenLedPin = 12; 								//The green LED is connected pin 12 of the Arduino.

  int RGBRedPin = 9; 									//The red RGB LED is connected pin 9 of the Arduino.
  int RGBGreenPin = 10; 								//The green RGB LED is connected pin 10 of the Arduino.
  int RGBBluePin = 11; 									//The blue RGB LED is connected pin 11 of the Arduino.

  int button1Pin = 2; 									//The SW1 button is connect to pin 2 of the Arduino.
  int button2Pin = 3; 									//The SW2 button is connect to pin 3 of the Arduino.

  volatile bool state = true;  							// Variable to store button1 state
  volatile bool state2 = false;  						// Variable to store button2 state

  int colors[3][3] = {{255,0,0},{0,255,0},{0, 0 ,255}}; // Array with RGB colors 

			//
			// Level 3  - cycling through three RGB colors
			//

/*

void setup() { 											//The Setup function runs once

  pinMode(greenLedPin, OUTPUT); 						//Setup green LED pin as an output pin.
  pinMode(redLedPin, OUTPUT); 							//Setup red LED pin as an output pin.

  attachInterrupt(digitalPinToInterrupt(button1Pin), level3ClickButton1, RISING); 	//Setup button1 pin as an input pin.
  attachInterrupt(digitalPinToInterrupt(button2Pin), level3ClickButton2, RISING); 	//Setup button2 pin as an input pin.
  
}



void loop() { 											//The loop function runs forever.

  while (state){ 										// Loop if true
    int time = 500;  									// Time between colors 
     
    for(int i = 0; i < sizeof(colors)/sizeof(colors[0]); i++){  // Searching color codes index to set in a fu
       
      if (state) { 										//Check to see if button1 stage changed
      
        turnOnLEDByRGB (colors[i][0], colors[i][1],colors[i][2]); 	//Turn on Led
        delay(time);  									// Delay to change light
    }
  }
}

  while (!state) { 										// Loop true
	turnOffRGBLED(); 									// Turn off RGB LED
  }
  
}

*/
			//
			// Level 4  - Green and Red LED to the circuit with RGB LED
			//



void setup() { 											//The Setup function runs once

  pinMode(greenLedPin, OUTPUT); 						//Setup green LED pin as an output pin.
  pinMode(redLedPin, OUTPUT); 							//Setup red LED pin as an output pin.

  attachInterrupt(digitalPinToInterrupt(button1Pin), clickButton1, RISING); 	//Setup button1 pin as an input pin.
  attachInterrupt(digitalPinToInterrupt(button2Pin), clickButton2, RISING); 	//Setup button2 pin as an input pin.
  
}

void loop() { 											//The loop function runs forever.


  if (state && !state2 ){ 								// Check to see buttons state 
    greenLedON(); 										// Turn on Green LED
    turnOffRGBLED(); 									// Turn off RGB LED
  }

  if (!state  && !state2){ 								// Check to see buttons state
	redLedON();    										// Turn on Red LED
    turnOffRGBLED(); 									// Turn off RGB LED
  }

  if (state && state2){ 								// Check to see buttons stat
	greenLedON(); 										// Turn on Green LED
    ciclyngRGBColors(500); 								// Turn On ciclying colors on RGB LED  
  }
  
  if (!state && state2){ 								// Check to see buttons state
    redLedON();     									// Turn on Red LED
    turnOffRGBLED(); 									// Turn off RGB LED
  	state2 = false;										// Turning off button 2
  }
}




	// Functions

// Change button 1 state
void clickButton1() {
  state = !state;										// Toggle value between true and false
}

// Change button 2 state
  void clickButton2() {
  state2 = !state2; 									// Toggle value between true and false
}


// Turn on Green LED
void greenLedON() {
  digitalWrite(greenLedPin, HIGH); 						// Turn on Green LED 
  digitalWrite(redLedPin, LOW); 						// Turn off Red LED 
}

// Turn on Red LED
void redLedON() {
  digitalWrite(greenLedPin, LOW); 						// Turn off Green LED 
  digitalWrite(redLedPin, HIGH); 						// Turn on Red LED 
}

// Turn On ciclying colors on RGB LED
void ciclyngRGBColors(int time) {
  
  int colorSize = sizeof(colors)/sizeof(colors[0]);		//Size of colors array

  for(int i = 0; i < colorSize; i++){  					// Searching color codes index to set in a fu
    if (state && state2) { 								//Check to see if button1 stage changed

      turnOnLEDByRGB (colors[i][0], colors[i][1],colors[i][2]); 	//Turn on Led
      delay(time);  									// Delay to change light
    }
  }
}

// Turn On led using RGB CODE
void turnOnLEDByRGB (int red, int green, int blue){
  analogWrite(RGBRedPin, red); 							//Turn on RGB RED
  analogWrite(RGBGreenPin, green);						//Turn on RGB GREEN
  analogWrite(RGBBluePin, blue); 						//Turn on RGB BLUE
}

// Turn off RGB LED
void turnOffRGBLED () {
  analogWrite(RGBRedPin, LOW); 							//Turn off RGB RED
  analogWrite(RGBBluePin, LOW); 						//Turn off RGB BLUE
  analogWrite(RGBGreenPin, LOW);						//Turn off RGB GREEN
}

// Change button 1 state - Level 3
void level3ClickButton1() {
	state = true;										// Change state to true
}

// Change button 2 state - Level 3
void level3ClickButton2() {
	state = false;										// Change state to false
}

  
  