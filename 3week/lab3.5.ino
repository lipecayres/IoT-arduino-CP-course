// C++

#define potentiometerPin A0
#define redPin 9
#define greenPin 11
#define bluePin 10


int potentiometer;  // get potentiometer data
String combination = "";  // get RGB combination 

bool letterCheck;  // validity check each typed letter 
char letter; // get each letter
int index = 0; // sequence counter



void setup() { //The Setup function runs once.

  pinMode(redPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(greenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(bluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
  pinMode(potentiometerPin,INPUT); //Setup rotationPin as an input.

  Serial.begin(9600); //Send data to the Serial monitor.
  
   
  Serial.println("Please input any combination of RGBCMYW letters");
  
  // read potentiometer
  potentiometer = 1023 - analogRead(potentiometerPin);

  // read RGB combination  
  while (index < 3){
    if (Serial.available()) {
      //get letters
      letter = Serial.read();
	
      // add letters to sequence
      combination += letter;
      combination.toLowerCase();
      index++;
    }
  }
      
} 


void loop() {
  
  // letters check
  if (validateLetter() == true){
    // change led color using letters from user
    for (int i=0; i<combination.length(); i++){ 
      changeColor(combination[i]);
      displayTrueMessage();
    }
  } else {
    displayFalseMessage();
    delay(1000);
  }

}


// change led color using code
void changeColor (char code) {

  potentiometer = analogRead(potentiometerPin);
  
//colors available
  switch(code) { 
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
    case 'c':  // power cyan color
      cyanLight();
      delay(potentiometer);
      ledOff();
      break;
    case 'm':  // power magenta color
      magentaLight();
      delay(potentiometer);
      ledOff();
      break;
    case 'y':  // power yellow color
      yellowLight();
      delay(potentiometer);
      ledOff();
      break;
    case 'w':  // power white color
      whiteLight();
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

// led cyan light
void cyanLight () {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 100);
  analogWrite(bluePin, 100);
}

// led magenta light
void magentaLight () {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
}

// led yellow light
void yellowLight () {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
}

// led yellow light
void whiteLight () {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}


// letter validity
bool validateLetter() {
  combination.toLowerCase();
  
  // errors counter
  int errors = 0;

  // checking each letter
  for (int i = 0; i<combination.length(); i++){  
    if (combination[i] != 'r' &&  
        combination[i] != 'g' &&
        combination[i] != 'b' &&	
        combination[i] != 'c' &&
        combination[i] != 'w' &&
        combination[i] != 'm' &&
        combination[i] != 'y' ) {
      errors++;
    } 
  }

  // verifying errors
  if(errors == 0){ 
    return true;
  } else {
    return false;
  }
}

// True message
void displayTrueMessage(){
  Serial.println("Colors pattern: " + combination);
}

// False message
void displayFalseMessage(){
  Serial.println("Error");
}