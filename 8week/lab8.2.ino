// C++
//Name: Jessica Nayara Pereira (Mar 22, 2023)

#include <IRremote.hpp>

#define bluePin 8
#define redPin 9

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK); 
}

void loop() {
  if (IrReceiver.decode()) {

    Serial.println(IrReceiver.decodedIRData.decodedRawData);

    IrReceiver.resume(); 

    switch (IrReceiver.decodedIRData.decodedRawData) {
      // number 1
      case 4010852096:  
      blueLightOn ();
      break;

      // number 2
      case 3994140416:  
      redLightOn();
      break;

      // number 3
      case 3977428736:  
      blueLightOff();
      break;

      // number 4
      case 3944005376:  
      redLightOff();
      break;

      // number 5
      case 3927293696:  
      flashBothLeds();
      flashBothLeds();
      flashBothLeds();
      
      break;
    }
  }
}


void flashBothLeds() {
  blueLightOn();
  redLightOn();
  delay(500);
  
  blueLightOff();
  redLightOff();
  delay(500);
}

// led blue light on
void blueLightOn() {
  analogWrite(bluePin, 255);
}

// led red light on
void redLightOn() {
  analogWrite(redPin, 255);
}

// led blue light off
void blueLightOff() {
  analogWrite(bluePin, 0);
}

// led red light off
void redLightOff() {
  analogWrite(redPin, 0);
}

