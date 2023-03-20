// C++

#define photoresistorPin A1
#define redPin 12
#define greenPin 8
#define bluePin 13
#define yellowPin 7


int photoresistor;  // get photoresistor data

int valueToConvert, moduleNumber, floorNumber; //values to convert to binary
String reverseValue, binary; // strings to save and print binary

void setup() { 

  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  pinMode(yellowPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);

  Serial.begin(9600);     
} 


void loop() {

// challenge 1
  
  // get data from photoresistor
  photoresistor = analogRead(photoresistorPin);

  // defining start values
  valueToConvert = photoresistor;
  moduleNumber = valueToConvert;
  floorNumber = 1;
  reverseValue = "";
  binary = "";


  // converting to binary 

    // restriction to stop division 
  while(floorNumber >0){
    moduleNumber = valueToConvert % 2;
    floorNumber = valueToConvert /2;
    reverseValue += moduleNumber;
    valueToConvert = floorNumber;
  }

  // reverting binary value 
  for(int i = reverseValue.length() - 1; i >= 0; i--){
    binary += reverseValue[i];
  }  

  // show at screen
  Serial.print("Photoresistor value: ");
  Serial.println(photoresistor);
  Serial.println("Binary value: " + binary);
  

// challenge 2
  
  if (photoresistor % 2 == 0 && photoresistor % 3 != 0){
    ledOff();
    greenLight();	
  }	else if (photoresistor % 2 != 0 && photoresistor % 3 == 0 ) {	
    ledOff();
    blueLight();
  } else if (photoresistor % 2 == 0 && photoresistor % 3 == 0){
    ledOff();
    redLight();
  } else {	
    ledOff();
    greenLight();
    blueLight();
    redLight();
  }

// extra challenge

  for (int i=0; i<reverseValue.length(); i++){

    if (binary[i] == '1'){
      yellowLightOn();
    } else if (binary[i] == '0') {				
      yellowLightOff();
    }
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

// led yelow light on
void yellowLightOn () {
  digitalWrite(yellowPin, HIGH);
  delay (1000);	
}

// led yelow light off
void yellowLightOff () {
  digitalWrite(yellowPin, LOW);
  delay (1000);
}

