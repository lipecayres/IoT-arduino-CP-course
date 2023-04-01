// C++
//Name: Jessica Nayara Pereira (Mar 22, 2023)


// Jessica's Light Show - Instructions:

// Power: Turn on/off system
// Forward: Next color
// Backward: Previous Color
// Play/pause: Pick a random color

#include <IRremote.hpp>

#define bluePin 9
#define redPin 11
#define greenPin 10

int thisColor, powerLight, powerShow;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(12, ENABLE_LED_FEEDBACK);
  randomSeed(analogRead(0));
  
}

void loop() {

  if (IrReceiver.decode()) {
    IrReceiver.resume(); 

    switch (IrReceiver.decodedIRData.decodedRawData) {
      // power
      
      case 4278238976:       
      
      powerLight++;
      if(powerLight >1){
        powerLight = 0; 
      }

      
      if (powerLight == 1){
        skipColor(thisColor);

      } else {
        ledOff ();
        thisColor = 0;
        powerShow = 0;
      }
      break;

      // play/pause
      case 4194680576:  

      if (powerLight ==1){
        colorShow ();
      }
      break;

      // backward
      case 4211392256:
      thisColor--;
      if(thisColor <= 0){
        thisColor = 0; 
      }
      skipColor(thisColor);
      break;

      // forward
      case 4177968896:  
      thisColor++;
      if(thisColor >= 6){
        thisColor = 6; 
      }
      skipColor(thisColor);
      break;

    }
  }
}






// led off
void ledOff () {
  analogWrite(redPin, LOW); 
  analogWrite(bluePin, LOW);
  analogWrite(greenPin, LOW); 
}


// random color show
void colorShow () {
 
  for(int i = 0; i<10; i++) {
    // get random value between 0 and 6 each time
    thisColor = random(1,7);

    // conditions to get different light
    skipColor(thisColor);
    delay(300);
  }
}


// skip color
void skipColor (int number) {

  switch (number) {
    // red color
    case 0: 
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
      Serial.println("Red");
    break;
    
    // green color
    case 1: 
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    Serial.println("Green");
    break;
    
    // blue color
    case 2: 
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    Serial.println("Blue");
    break;
    
    // yelloy color
    case 3: 
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    Serial.println("Yellow");
    break;
    
    // cyan color
    case 4: 
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    Serial.println("Cyan");
    break;
    
    // magenta color
    case 5: 
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    Serial.println("Magenta");
    break;
    
    // white color
    case 6: 
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    Serial.println("White");
    break;
    

  }}
