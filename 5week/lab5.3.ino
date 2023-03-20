// C++

#define redPin 9
#define greenPin 11
#define bluePin 10

#define greenLED 12
#define redLED 13

#define btn1 2
#define btn2 3


volatile bool status1; // btn status on/off


void setup() { 

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(btn1), click1, RISING);
  attachInterrupt(digitalPinToInterrupt(btn2), click2, RISING);
} 


void loop() {

  if (status1){
    redLight();
    delay(500);   
  }
  if (status1){
    greenLight();
    delay(500);   
  }
  if (status1){
    blueLight();
    delay(500);   
  }
  
  if (!status1){
    ledOff();
  }

}




// led off
void ledOff () {
  analogWrite(redPin, LOW); 
  analogWrite(bluePin, LOW);
  analogWrite(greenPin, LOW); 
}

// led red light
void redLight () {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0); 
  analogWrite(bluePin, 0);
}

// led green light
void greenLight () {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
}

// led blue light
void blueLight () {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
}

// change btn1 status
void click1() {
	status1 = true;	
}

// change btn2 status
void click2() {
	status1 = false;
}