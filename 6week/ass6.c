//
// Assignment 5 - Level 3 and 4
// 200548559 - Felipe Simoes Cayres 
//

// Prototypes
#include <LiquidCrystal.h>

// Variables

  LiquidCrystal lcd( 12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack board.


//Initialise the Serial LCD.


			//
			// Level 2  - Shift your name back and forth across the LCD
			//


void setup() {
  
  lcd.begin (16,2); //Initialize the LCD.
}

void loop(){
  
  
void checkLengthName(String str1 , String str2) {

  int length;
  int str1Size = sizeof(str1);
  int str2Size = sizeof(str2);
  
  if(str1 >= str2){
    lengthToAdd = str1;
  } else {
  	lengthToAdd = str2;
  }  
  
  return length;
}  
  
  
  String name = "Felipe";
  String lastName = "Cayres";
  int lengthToAdd = 0;
  
  int nameSize = sizeof(name);
  int lastNameSize = sizeof(lastName);
  
  if(nameSize >= lastNameSize){
    lengthToAdd = nameSize;;
  } else {
  	lengthToAdd = lastNameSize;
  }
  
  for (int i = 0; i < lengthToAdd; i++){
  	name += " ";
    lastName += " ";
  }
   
  for (int i = 0; i <= 16 - lengthToAdd; i++){
    lcd.clear();
    lcd.setCursor(i,0); //goto first column and first line (0,0)
    lcd.print("Felipe"); //Print at cursor Location   
 //   lcd.setCursor(i,1); //goto first column and second line
 //   lcd.print("Cayres"); //Print at cursor Location
    delay(500);
   }
  
  for (int i = 16-lengthToAdd; i >= 0; i--){
    lcd.clear();
//    lcd.setCursor(i,0); //goto first column and first line (0,0)
//    lcd.print("Felipe"); //Print at cursor Location   
    lcd.setCursor(i,1); //goto first column and second line
    lcd.print("Felipe"); //Print at cursor Location
    delay(500);
   }  
  
 }







			//
			// Level 4  - Green and Red LED to the circuit with RGB LED
			//





	// Functions
