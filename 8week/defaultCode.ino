#include <IRremote.hpp>

#define blueLed 7


void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(11, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {

  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData); // Print "old" raw data

    IrReceiver.resume(); // Enable receiving of the next value


    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 4278238976: // power

      digitalWrite(blueLed,HIGH);

      break;
      case 4261527296:  // vol+

      digitalWrite(blueLed,LOW);

      break;
      case 4244815616:  // func/Stop

      // insert code here
		Serial.println("Felipe");
      break; 
      case 4211392256: // backward

      // insert code here

      break;
      case 4194680576:  // play/pause

      // insert code here


      break;
      case 4177968896:  // forward

      // insert code here


      break;
      case 4144545536:  // down

      // insert code here


      break;
      case 4127833856:  // vol-

      // insert code here


      break;
      case 4111122176:  // up

      // insert code here


      break;
      case 4077698816:  // number 0

      // insert code here


      break;
      case 4060987136:  // EQ

      // insert code here


      break;
      case 4044275456:  // ST/REPT

      // insert code here


      break;
      case 4010852096:  // number 1

      // insert code here


      break;
      case 3994140416:  // number 2

      // insert code here


      break;
      case 3977428736:  // number 3

      // insert code here


      break;
      case 3944005376:  // number 4

      // insert code here


      break;
      case 3927293696:  // number 5

      // insert code here


      break;
      case 3910582016:  // number 6

      // insert code here


      break;
      case 3877158656:  // number 7

      // insert code here


      break;
      case 3860446976:  // number 8

      // insert code here


      break;
      case 3843735296:  // number 9 

      // insert code here


      break; 
      default:
      Serial.print("Error");
      break;

    }

  }

}



/*

Button KEYS

Power: 4278238976
Vol+: 4261527296
Func/Stop: 4244815616
Backward: 4211392256
Play/pause: 4194680576
Forward: 4177968896
Down: 4144545536
Vol-: 4127833856
Up: 4111122176
0: 4077698816
EQ: 4060987136
ST/REPT: 4044275456
1: 4010852096
2: 3994140416
3: 3977428736
4: 3944005376
5: 3927293696
6: 3910582016
7: 3877158656
8: 3860446976
9: 3843735296

*/