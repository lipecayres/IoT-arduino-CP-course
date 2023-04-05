// 200548559 - Felipe Cayres
// Mar 29, 2023
// Slave

#include <Wire.h>
#include <Servo.h>

#define RGBRedPin 11
#define RGBGreenPin 9
#define RGBBluePin 10

Servo myservo;

int pushPosition;


//Variables
  int position, steps = 25, corner, timeRotation = 300;


void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  
  Serial.begin(9600);           // start serial for output
  
  myservo.attach(4);


  // Servo initial positon
  myservo.write(0);

  // Servo initial color
  turnOnLEDByKey(position);


}

void loop()
{
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

  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  pushPosition = Wire.read();

  if (pushPosition ==1){
    clickButton1 ();
  } else if (pushPosition == 2) {
    clickButton2 ();
  }

  Serial.println(pushPosition);
  pushPosition = 0;
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
