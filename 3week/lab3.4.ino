// C++

#define potentiometerPin A0
#define redPin 9
#define greenPin 11
#define bluePin 10


int potentiometer;  // get potentiometer data
String combination = "";  // get RGB combination 


// Setup

void setup() { //The Setup function runs once.

  pinMode(redPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(greenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(bluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
  pinMode(potentiometerPin,INPUT); //Setup rotationPin as an input.

  Serial.begin(9600); //Send data to the Serial monitor.
  
   
  Serial.println("Please input any combination of R, G or B letters");
  
    // read potentiometer
  potentiometer = 1023 - analogRead(potentiometerPin);

  // read RGB combination 
  char letter;
  int index = 0;
  
  while (index <3){
    if (Serial.available()) {
      //Read typed characters 
      letter = Serial.read();

      //Add characters inputed by user
      combination += letter;
      index++;
    }
  }
} 


void loop() {

  // iteraction of all typed colors 
  for (int i=0; i<combination.length(); i++){ 
    // change led color using letters from user
    changeColor(combination[i]);
  }
}


// change led color using code
void changeColor (char code) {

  potentiometer = analogRead(potentiometerPin);
  switch(code) { // Selecting colors to display 
    case 'r':  // power red light
      redLight();
      delay(potentiometer);
      ledOff();
      break;
    case 'g': // power green light
      greenLight();
      delay(potentiometer);
      ledOff();
      break;
    case 'b':  // power blue light
      blueLight();
      delay(potentiometer);
      ledOff();
      break;
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