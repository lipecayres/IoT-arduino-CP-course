// C++

#define potentiometerPin A0
#define redPin 9
#define greenPin 11
#define bluePin 10

int potentiometer;  // get potentiometer data
int time = 0; // time to delay lights



void setup() {

  pinMode(redPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(greenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(bluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
  pinMode(potentiometer,INPUT); //Setup potentiometerPin as an input.

} 


void loop() { 
  
  // Get potentiometer data
  potentiometer = analogRead(potentiometerPin);
  time = 1023 - potentiometer;
  
  // Turn on RED LED
  analogWrite(redPin, 255); //Turn on RED
  analogWrite(greenPin, 0); //Turn on GREEN
  analogWrite(bluePin, 0); //Turn on BLUE
  delay(time);

  // Turn on Green LED
  analogWrite(redPin, 0); //Turn on RED
  analogWrite(greenPin, 255); //Turn on GREEN
  analogWrite(bluePin, 0); //Turn on BLUE
  delay(time);
  
  // Turn on Blue LED
  analogWrite(redPin, 0); //Turn on RED
  analogWrite(greenPin, 0); //Turn on GREEN
  analogWrite(bluePin, 255); //Turn on BLUE
  delay(time);
}

