// C++

#define potentiometerPin A0
#define redPin 9
#define greenPin 11
#define bluePin 10

int potentiometer;  // get potentiometer data


void setup() { 

  pinMode(redPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(greenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(bluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
  pinMode(potentiometerPin,INPUT); //Setup rotationPin as an input.
  
} 


void loop(){

  int potentiometer = analogRead(potentiometerPin); 

  // Change colors using rainbow pattern (ROYGBP)
  if (potentiometer <= 150){        
    analogWrite(redPin, 255); 
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 0); 
  } 
  else if (potentiometer <= 300 ){
    analogWrite(redPin, 255); 
    analogWrite(greenPin, 165); 
    analogWrite(bluePin, 0); 
  } 
  else if (potentiometer <= 450){
    analogWrite(redPin, 255); 
    analogWrite(greenPin, 255); 
    analogWrite(bluePin, 0); 
  } 
  else if (potentiometer <= 600){
    analogWrite(redPin, 0); 
    analogWrite(greenPin, 255); 
    analogWrite(bluePin, 0);
  } 
  else if (potentiometer <= 750){
    analogWrite(redPin, 0); 
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 255); 
  } 
  else if (potentiometer <=900){
    analogWrite(redPin, 128);
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 128);
  }
}
