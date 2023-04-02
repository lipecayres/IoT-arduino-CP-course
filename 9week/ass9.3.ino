// 200548559 - Felipe Cayres
// Mar 29, 2023

#include <Servo.h>

#define button1Pin 3
#define button2Pin 2

#define RGBRedPin 11
#define RGBGreenPin 9
#define RGBBluePin 10


Servo myservo;

//Variables
  int position, steps = 25, corner, timeRotation = 300;
  
void setup(){

  Serial.begin(9600);
  // Servo pin
  myservo.attach(4);

  // button pins
  attachInterrupt(digitalPinToInterrupt(button1Pin), clickButton1, RISING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), clickButton2, RISING);

  // Servo initial positon
  myservo.write(0);

  // Servo initial color
  turnOnLEDByKey(position);

}


void loop() {
  
  if (corner == 1) {
    setPosition (135);
    delay(timeRotation);

    setPosition (90);
    delay(timeRotation);

    setPosition (45);
    delay(timeRotation);
    
	corner =0;
 
    myservo.write(position);
    turnOnLEDByKey(position);
  }

  if (corner == -1) {
    setPosition (45);
    delay(timeRotation);

    setPosition (90);
    delay(timeRotation);

    setPosition (135);
    delay(timeRotation);
    
    corner =0;

    myservo.write(position);
    turnOnLEDByKey(position);

  }

}


// Button 1 click
void clickButton1 () {
  position = myservo.read() + 180*steps/100;
  if (position > 180) {
    position = 0;
    corner = 1;
  }
   
  myservo.write(position);
  turnOnLEDByKey(position);
  Serial.println(position);
}

// Button 2 click
void clickButton2 () {
  position = myservo.read() - 180*steps/100;
  if (position < 0) {
	position = 180;
    corner = -1;
  }
  
  myservo.write(position);
  turnOnLEDByKey(position);
  Serial.println(position);
}

// Turn On led using KEY NUMBER
void turnOnLEDByKey (int color) {

  switch(color) { // Selecting colors to display 
    case 0:  // Red color
      turnOnLEDByRGB(255,0,0);
      break;
    case 45: // Green color
      turnOnLEDByRGB(0,255,0);
      break;
    case 90:  // Blue color
      turnOnLEDByRGB(0,0,255);
      break;
    case 135:  // cyan color
      turnOnLEDByRGB(0,100,100);
      break;
    case 180:  // magenta color
      turnOnLEDByRGB(255,0,255);
      break;
  }
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

// Set position + color
void setPosition (int code) {
  myservo.write(code);
  turnOnLEDByKey(code);
}