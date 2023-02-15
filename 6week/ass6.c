//
// Assignment 6
// 200548559 - Felipe Simoes Cayres 
//

// Prototypes
#include <LiquidCrystal.h>

// Variables

  LiquidCrystal lcd( 12,11,7,6,5,4); //These pin numbers are hard coded in on the serial backpack board.
  String name = "Felipe";

  int button1Pin = 2; 									//The SW1 button is connect to pin 2 of the Arduino.
  int button2Pin = 3; 									//The SW2 button is connect to pin 3 of the Arduino.

  volatile int state = 0;   							// Variable to store button1 state
  volatile int state2 = 0;   							// Variable to store button2 state

  String display[3] = {"Felipe","Crossfit","Salad"};
  int displaySize[3] = {6,8,5};
			//
			// Level 2  - Shift your name back and forth across the LCD
			//

/*

void setup() {
  
  lcd.begin (16,2); //Initialize the LCD.
}

void loop(){
  
   
  for (int i = 0; i <= 16 - sizeof(name); i++){
    lcd.clear();
    lcd.setCursor(i,0); //goto first column and first line (0,0)
    lcd.print(name); //Print at cursor Location   
    delay(500);
   }
  
  for (int i = 16-sizeof(name); i >= 0; i--){
    lcd.clear();
    lcd.setCursor(i,1); //goto first column and second line
    lcd.print(name); //Print at cursor Location
    delay(500);
   }  
  
 }

*/

			//
			// Level 3  - Green and Red LED to the circuit with RGB LED
			//

/*

void setup() {
  
  lcd.begin (16,2); //Initialize the LCD.
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(button1Pin), clickButton1, RISING); 	//Setup button1 pin as an input pin.
  
}

void loop(){
  
  String displayWord = display[state];
  int displayWordSize = displaySize[state];
  
  Serial.println("State: " + state);
  Serial.println("Display Word: " + displayWord);  
  Serial.println("Display Size: " + (String)displayWordSize);
  Serial.println("---------------");
  
  
  for (int i = 0; i <= 16 - displayWordSize; i++){
      displayWord = display[state];
	  displayWordSize = displaySize[state];
    
      lcd.clear();
      lcd.setCursor(i,0); //goto first column and first line (0,0)
      lcd.print(displayWord); //Print at cursor Location   
      delay(500);    
    
   }
  
  for (int i = 16-displayWordSize; i >= 0; i--){
    displayWord = display[state];
	displayWordSize = displaySize[state];
    
    lcd.clear();
    lcd.setCursor(i,1); //goto first column and second line
    lcd.print(displayWord); //Print at cursor Location
    delay(500);
   }  
}


*/


			//
			// Level 4  - Short Survey with yes/no question buttons
			//

// Variables

  String questions[5] {"Do you have any pets?",
                       "Do you talk in your sleep?",
                       "Do you like your job?",
                       "Do you play sports?",
                       "Do you drink coffee?"
                      };

  int answers[5] = {9,9,9,9,9};
  int yesOrNo[2] = {0,0};
  int iteration = 0;
  int resetButton = 0;


void setup() {
  
  lcd.begin (16,2); //Initialize the LCD.
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(button1Pin), level4ClickButton1, RISING); 	//Setup button1 pin as an input pin.
  attachInterrupt(digitalPinToInterrupt(button2Pin), level4ClickButton2, RISING); 	//Setup button2 pin as an input pin.
  
}

void loop(){
  
  resetButton =0;
  
  for (int i =0; i < 5; i++){
    iteration = i;
    
    while (answers[i] == 9){
 	 	displayQuestion(questions[i]);
    }
  }
  
  totalAnswers();
  
  resetButton =0;
  iteration = 0;

  
  while (resetButton <= 2){
    if (answers[4] != 9) {
      
      lcd.clear();
      lcd.setCursor(0,0); //goto first column and first line (0,0)
      lcd.print("Answer's Summary"); //Print at cursor Location 
      lcd.setCursor(0,1); //goto first column and first line (0,0)
      lcd.print("Yes: " + (String)yesOrNo[0] + " | " + "No: " + (String)yesOrNo[1]); //Print at cursor Location 
      delay(2000);

      lcd.clear();
      lcd.setCursor(0,0); //goto first column and first line (0,0)
      lcd.print("Want to restart?"); //Print at cursor Location 
      lcd.setCursor(0,1); //goto first column and first line (0,0)
      lcd.print("Press 3x Yes btn "); //Print at cursor Location 
      delay(2000);

    }
  }

  if (resetButton == 3){
    for (int i = 0; i<sizeof(answers); i++){
      answers[i] = 9;
     
      if (i<2){
      	yesOrNo[i] = 0;
      }
    }

    iteration = 0;
    
    lcd.clear();
    lcd.setCursor(0,0); //goto first column and first line (0,0)
    lcd.print("Restarting"); //Print at cursor Location 
    lcd.setCursor(0,1); //goto first column and first line (0,0)
    lcd.print("Please wait... "); //Print at cursor Location 
    delay(2000);

  }
}

	// Functions

int checkLengthName(String str1 , String str2) {

  int length;
  
  if(sizeof(str1) >= sizeof(str2)){
    length = sizeof(str1);
  } else {
  	length = sizeof(str2);
  }  
  
  return length;
}  


// Change button 1 state
void clickButton1() {
  state += 1;								// Change state between 1 to 3

  if (state >2){
    state = 0;
  }
}


void displayQuestion(String question) {
  String displayUp;
  String displayDown;
  int questionSize = question.length();

  for (int i =0; i< questionSize; i++){
    if (i<16){
      displayUp += question[i];
    } else {
      displayDown += question[i];
      }
  
  }
  	
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (0,0)
  lcd.print(displayUp); //Print at cursor Location 
  lcd.setCursor(0,1); //goto first column and first line (0,0)
  lcd.print(displayDown); //Print at cursor Location 
  delay(500); 
}

void totalAnswers(){
  for (int i=0; i<5;i++){
    if (answers[i] == 1){
      yesOrNo[0] +=1;
    } else if (answers[i] == 0){
      yesOrNo[1] +=1;
    }
  }
}
  
// Change button 1 state level 4
void level4ClickButton1 () {
  answers[iteration] = 1;
  resetButton +=1;
}

// Change button 2 state level 4
void level4ClickButton2 () {
  answers[iteration] = 0;
}