// 200548559 - Felipe Cayres
// Mar 20, 2023

#include <IRremote.hpp>
#define RGBBluePin 12
#define RGBRedPin 8

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {

  if (IrReceiver.decode()) {
    IrReceiver.resume(); // Enable receiving of the next value

    switch (IrReceiver.decodedIRData.decodedRawData) {

      case 4010852096:  // number 1
        digitalWrite(RGBBluePin,HIGH);

      break;
      case 3994140416:  // number 2
        digitalWrite(RGBRedPin,HIGH);

      break;
      case 3977428736:  // number 3
        digitalWrite(RGBBluePin,LOW);

      break;
      case 3944005376:  // number 4
        digitalWrite(RGBRedPin,LOW);

      break;
      case 3927293696:  // number 5

        flashLed(3);  // flash LED 3 times

      break;
    }
  }
}


void flashLed(int times) {
  int number=0;
  
  while (number <times){
    digitalWrite(RGBBluePin,HIGH);
    digitalWrite(RGBRedPin,HIGH);
    delay(500);
    digitalWrite(RGBBluePin,LOW);
    digitalWrite(RGBRedPin,LOW);
    delay(500);
    number++;
  }
}
