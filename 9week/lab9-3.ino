// C++
//Name: Jessica Naiara Pereira
//Date: Apr 01, 2023

#include <Servo.h>

#define btn1 3
#define btn2 2

#define bluePin 11
#define redPin 10
#define greenPin 12


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
  selectColor(degree);
  
}

// on click button 1
void onClick1 () {
  degree = myservo.read() + 180 * steps / 100;
  if (degree > 180) {
    degree = 0;
  }
}

// on click button 2
void onClick2 () {
  degree = myservo.read() - 180 * steps / 100;
  if (degree < 0) {
    degree = 180;
  }

}



// chooose LED color
void selectColor (int angle) {

  switch(angle) {
    // red
    case 0:
      ledRGBCode(255,0,0);
      break;
    // green
    case 45: 
      ledRGBCode(0,255,0);
      break;
    // blue
    case 90:  
      ledRGBCode(0,0,255);
      break;
    // pink
    case 135:  
      ledRGBCode(255,105,180);
      break;
    // orange
    case 180:  
      ledRGBCode(255,165,0);
      break;
  }
}

// led on using rgb code
void ledRGBCode (int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

// led off
void ledOff () {
  analogWrite(redPin, LOW); 
  analogWrite(bluePin, LOW);
  analogWrite(greenPin, LOW); 
}