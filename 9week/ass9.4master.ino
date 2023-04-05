// 200548559 - Felipe Cayres
// Mar 29, 2023
// Master


#include <Wire.h>

#define button1Pin 3
#define button2Pin 2




// Variables

int pushPosition;

void setup()
{

  // join i2c bus (address optional for master)
  Wire.begin();

  Serial.begin(9600);

  // button pins
  attachInterrupt(digitalPinToInterrupt(button1Pin), clickButton1, RISING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), clickButton2, RISING);

}

void loop()
{
  
  if (pushPosition ==1){
    Wire.beginTransmission(4); 
    Wire.write(pushPosition); 
    Wire.endTransmission(); 
    delay(500);
  } else if (pushPosition == 2) {
    Wire.beginTransmission(4); 
    Wire.write(pushPosition); 
    Wire.endTransmission(); 
    delay(500);
  }

  pushPosition = 0;
}

// Button 1 click
void clickButton1()
{
 pushPosition = 1;
}

// Button 2 click
void clickButton2()
{
 pushPosition = 2;
}
