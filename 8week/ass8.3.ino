// 200548559 - Felipe Cayres
// Mar 20, 2023

#include <IRremote.hpp>

#define RGBBluePin 9
#define RGBRedPin 11
#define RGBGreenPin 10

bool powerLed;

  double brightnessStep = 63.75; // amount of brightness change per button press
  double currentBrightness = 255; // initial brightness
  double bright;
  int currentColor = 0; // initial color


void setup()
{
  pinMode(RGBRedPin, OUTPUT);
  pinMode(RGBGreenPin, OUTPUT);
  pinMode(RGBBluePin, OUTPUT);
  
  Serial.begin(9600);
  IrReceiver.begin(12, ENABLE_LED_FEEDBACK); // Start the receiver


  
}

void loop() {

  
  if (IrReceiver.decode()) {
	
    Serial.print("Button code:"); 
    Serial.println(IrReceiver.decodedIRData.decodedRawData); // Print "old" raw data

    IrReceiver.resume(); // Enable receiving of the next value

    
    switch (IrReceiver.decodedIRData.decodedRawData) {
	  case 4278238976: // power
		powerLed = !powerLed;
		
      if (powerLed){
      	changeColor();
        Serial.println("Led ON");
        
      } else {
      	turnOffRGBLED();
        currentColor = 0;
        Serial.println("LED Off");
          
      }
      break;

      
      // vol+
      case 1435311209:  // vol+
      case 2103369920:  // vol+
      case 2130763648:  // vol+
      case 3220621147:  // vol+
      case 4261527296:  // vol+
      case 591179241:  // vol+
      case 624734483:  // vol+
      
        upBright();
        changeColor ();
      
        bright = currentBrightness/255*100;
        Serial.print("brightness at: ");
        Serial.println(bright);

      break;
      
	// play/pause
      case 4194680576:  // play/pause
      case 1025390575:  // play/pause
      case 4020893925:  // play/pause
      case 1267674629:  // play/pause
      case 991835333:  // play/pause

      	currentColor = (currentColor + 1) % 3; // cycle through the colors
	    changeColor ();      
        Serial.print("color code: ");        
      	Serial.println(currentColor);      
      
        break;
	
	// vol -
      case 1286666975:  // vol-
      case 1253111733:  // vol-
      case 2063916928:  // vol-
      case 2061620581:  // vol-
      case 293660318:  // vol-
      case 3679338629:  // vol-
      case 4127833856:  // vol-
      case 453304192:  // vol-
      case 50651008:  // vol-

      
	    downBright ();
        changeColor ();
		bright = currentBrightness/255*100;
        Serial.print("brightness at: ");
        Serial.println(bright);
        break;
      }
  }
}

	// Increase bright
void upBright() {
  if (currentBrightness < 255) {
    currentBrightness += brightnessStep; // increase brightness
  }
  
  if (currentBrightness>255){
  	currentBrightness = 255;
  }
}

	// Decrease bright
void downBright (){
  if (currentBrightness > 0) {
    currentBrightness -= brightnessStep; // decrease brightness

  }
  
  if (currentBrightness<0){
  	currentBrightness = 0;
  }
}

	// Change color
void changeColor () {

  switch (currentColor) {
    case 0: // red
    analogWrite(RGBRedPin, currentBrightness);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 0);
    break;
    case 1: // green
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, currentBrightness);
    analogWrite(RGBBluePin, 0);
    break;
    case 2: // blue
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, currentBrightness);
    break;

  }
}

// Turn off RGB LED
void turnOffRGBLED () {
  analogWrite(RGBRedPin, LOW);
  analogWrite(RGBBluePin, LOW);
  analogWrite(RGBGreenPin, LOW);
}