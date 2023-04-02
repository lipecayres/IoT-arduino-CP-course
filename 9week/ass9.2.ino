// 200548559 - Felipe Cayres
// Mar 29, 2023

#include <Servo.h>

#define button1Pin 3
#define button2Pin 2

Servo myservo;

//Variables
  int position, steps = 25;
  
void setup(){
	
  // Servo pin
  myservo.attach(4);

  // button pins
  attachInterrupt(digitalPinToInterrupt(button1Pin), clickButton1, RISING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), clickButton2, RISING);

  // Servo initial positon
  myservo.write(0);

  }
  

void loop() {}


void clickButton1 () {
  position = myservo.read() + 180 * steps / 100;
  if (position > 180) {
    position = 180;
  }
  myservo.write(position);
}


void clickButton2 () {
  position = myservo.read() - 180 * steps / 100;
  if (position < 0) {
    position = 0;
  }
  myservo.write(position);
}
