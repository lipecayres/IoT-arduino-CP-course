// C++
//Name: Jessica Naiara Pereira
//Date: Apr 01, 2023


#include <Wire.h>

#define btn1 3
#define btn2 2


int click = 0;

  
void setup() {

    Wire.begin();
  
  // btn pin 
  attachInterrupt(digitalPinToInterrupt(btn1), onClick1, RISING);
  attachInterrupt(digitalPinToInterrupt(btn2), onClick2, RISING);

}

void loop()
{
  if (click ==1){
    Wire.beginTransmission(4); 
    Wire.write(click); 
    Wire.endTransmission(); 
    delay(300);
  } else if (click == 2) {
    Wire.beginTransmission(4); 
    Wire.write(click); 
    Wire.endTransmission(); 
    delay(300);
  }

  click = 0;
}

// on click 1
void onClick1()
{
 click = 1;
}

// on click 2
void onClick2()
{
 click = 2;
}
