// C++
//Name: Jessica Naiara Pereira
//Date: Apr 01, 2023



#include <Wire.h>
#include <Servo.h>

#define bluePin 11
#define redPin 10
#define greenPin 12

Servo myservo;

  int degree = 0; 
  int steps = 25;
  int click = 0;

void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent); 
  
  Serial.begin(9600);
  
  myservo.attach(4);
}

void loop() {
  // servo angle on click position
  myservo.write(degree);
  selectColor(degree);
  delay(200);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  click = Wire.read();

  if (click ==1){
    onClick1 ();
    Serial.print("1");
  } else if (click == 2) {
    onClick2 ();
    Serial.print("2");

  }

  Serial.println(click);
  click = 0;
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