// C++

// import packacge
#include <LiquidCrystal.h>

// pins on arduino
#define btn 2

// LCD settings
LiquidCrystal lcd( 12,11,7,6,5,4);

// name to display
String name = "Jessica"; 
String hobby = "Netflix";
String lunch = "Spaghetti";

String displayMessage;

// name length
int nameLength = name.length();  

// btn position to display message
int status = 0;  



void setup() {
  
  // initialize LCD
  lcd.begin (16,2);
  Serial.begin(9600);
  // initialize btn
  attachInterrupt(digitalPinToInterrupt(btn), click1, RISING); 	//Setup button1 pin as an input pin.

}

void loop(){
  
  // display name left to right at top row
  for (int i = 0; i <= 16 - displayMessage.length(); i++){
    
	statusBtn();

    lcd.clear();
    lcd.setCursor(i,0);
    lcd.print(displayMessage);
    delay(1000);
   }
  
  // display name right to left at bottom row  
  for (int i = 16-displayMessage.length(); i >= 0; i--){

	statusBtn();
    
    lcd.clear();
    lcd.setCursor(i,1);
    lcd.print(displayMessage); 
    delay(1000);
   }  

 }


// change btn1 status
void click1() {
	status++;
  if (status >=3){
  	status = 0;
  }
  
}

// check status btn
void statusBtn (){
  if(status == 0){
    displayMessage = name;
  } else if (status == 1) {
    displayMessage = hobby;
  } else {
    displayMessage = lunch;
  }
}