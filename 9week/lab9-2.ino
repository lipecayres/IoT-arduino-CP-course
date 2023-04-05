// C++
//Name: Jessica Naiara Pereira
//Date: Apr 01, 2023

#include <Servo.h>

#define btn1 3
#define btn2 2

Servo myservo;

  // servo angle
  int degree = 0;
  // servo step each click
  int steps = 25;

void setup(){
  
  Serial.begin(9600);
  
  myservo.attach(4);

  attachInterrupt(digitalPinToInterrupt(btn1), onClick1, RISING);
  attachInterrupt(digitalPinToInterrupt(btn2), onClick2, RISING);
	
}
  

void loop() {

  // servo angle on click position
  myservo.write(degree);
  
}

// on click button 1
void onClick1 () {
  degree = myservo.read() + 180 * steps / 100;
  if (degree > 180) {
    degree = 180;
  }
}

// on click button 2
void onClick2 () {
  degree = myservo.read() - 180 * steps / 100;
  if (degree < 0) {
    degree = 0;
  }

}
