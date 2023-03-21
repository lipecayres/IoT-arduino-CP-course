// C++

// import packacge
#include <LiquidCrystal.h>

// LCD settings
LiquidCrystal lcd( 12,11,7,6,5,4);

// name to display
String name = "Jessica";
int nameLength = name.length();

void setup() {
  
  // initialize the LCD.
  lcd.begin (16,2);
}

void loop(){
  
  // display name left to right at top row
  for (int i = 0; i <= 16 - nameLength; i++){
    lcd.clear();
    lcd.setCursor(i,0);
    lcd.print(name);
    delay(1000);
   }
  
  // display name right to left at bottom row  
  for (int i = 16-nameLength; i >= 0; i--){
    lcd.clear();
    lcd.setCursor(i,1);
    lcd.print(name); 
    delay(1000);
   }  
  
 }
