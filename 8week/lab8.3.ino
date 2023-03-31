// C++
//Name: Jessica Nayara Pereira (Mar 22, 2023)

#include <IRremote.hpp>


#define bluePin 9
#define redPin 11
#define greenPin 10

// bright control
float brightChange = 85, currentBrightness = 255;

int thisColor, brightPercentage; 

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(12, ENABLE_LED_FEEDBACK); 
  
  skipColor();
}

void loop() {
  if (IrReceiver.decode()) {

    IrReceiver.resume(); 

    switch (IrReceiver.decodedIRData.decodedRawData) {
      // vol+
      case 4261527296:  
		Serial.println("vol+");
      increaseBright();
      skipColor ();
      
		brightPercentage = currentBrightness/255*100;
        Serial.print("brightness at: ");
        Serial.println(brightPercentage);
      break;
      
	  // vol-
      case 4127833856:  
      decreaseBright();
      skipColor();

      brightPercentage = currentBrightness/255*100;
      Serial.print("brightness at: ");
      Serial.println(brightPercentage);
      
      break;
      
      // play/pause
      case 4194680576: 
      
      if (thisColor<2){
      thisColor++;
      } else {
      thisColor = 0;
      }
      
      skipColor();      
      break;
 
    }
  }
}

// increase light bright
void increaseBright() {
  
  //check value and change brightness
  if (currentBrightness>255){
    currentBrightness = 255;  
  } else if(currentBrightness < 255) {
    currentBrightness += brightChange;
  }
}

// reduce light bright
void decreaseBright (){
  
  //check value and change brightness
  if (currentBrightness<0){
  	currentBrightness = 0;  
  } else if(currentBrightness > 0) {
    currentBrightness -= brightChange;
  }
}

// skip color
void skipColor () {

  switch (thisColor) {
    // red color
    case 0: 
    analogWrite(redPin, currentBrightness);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
      Serial.println("Red");
    break;
    
    // green color
    case 1: 
    analogWrite(redPin, 0);
    analogWrite(greenPin, currentBrightness);
    analogWrite(bluePin, 0);
    Serial.println("Green");
    break;
    
    // blue color
    case 2: 
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, currentBrightness);
    Serial.println("Blue");
    break;
  }
}
