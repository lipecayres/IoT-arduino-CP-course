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


		// Level 4
  String questions[5] {"Do you have any pets?",
                       "Do you talk in your sleep?",
                       "Do you like your job?",
                       "Do you play sports?",
                       "Do you drink coffee?"
                      };

  int answers[5] = {9,9,9,9,9};
  int yesOrNo[2];
  int iteration;
  int resetButton;


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
  
  for (int i = 0; i <= 16 - display[state].length(); i++){
    
      lcd.clear();
      lcd.setCursor(i,0); //goto first column and first line (0,0)
      lcd.print(display[state]); //Print at cursor Location   
      delay(500);    
    
   }
  
  for (int i = 16-display[state].length(); i >= 0; i--){
    
    lcd.clear();
    lcd.setCursor(i,1); //goto first column and second line
    lcd.print(display[state]); //Print at cursor Location
    delay(500);
   }  
}

*/

			//
			// Level 4  - Short Survey with yes/no question buttons
			//



void setup() {
  
  lcd.begin (16,2); //Initialize the LCD.
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(button1Pin), level4ClickButton1, RISING); 	//Setup button1 pin as an input pin.
  attachInterrupt(digitalPinToInterrupt(button2Pin), level4ClickButton2, RISING); 	//Setup button2 pin as an input pin.
  
}

void loop(){
  
  
  resetButton =0;				
  
	  // Display questions stored in an array
  for (int i =0; i < 5; i++){		
    iteration = i;
    
    while (answers[i] == 9){
 	 	displayQuestion(questions[i]);
    }
  }

  	// Getting answers 
  
  totalAnswers();
  
  
    // Display yes/no quantity - restart message 
  
  resetButton =0;
  iteration = 0;

  
  while (resetButton <= 2){
    if (answers[4] != 9) {
      
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Answer's Summary"); 
      lcd.setCursor(0,1); 					
      lcd.print("Yes: " + (String)yesOrNo[0] + " | " + "No: " + (String)yesOrNo[1]); //Print at cursor Location 
      delay(2000);

      lcd.clear();
      lcd.setCursor(0,0); 					//goto first column and first line (0,0)
      lcd.print("Want to restart?"); 		//Print at cursor Location 
      lcd.setCursor(0,1); 					//goto first column and first line (0,0)
      lcd.print("Press 3x Yes btn "); 		//Print at cursor Location 
      delay(2000);

    }
  }

      // Restart function 
  
  if (resetButton == 3){
    for (int i = 0; i<sizeof(answers); i++){
      answers[i] = 9;
     
      if (i<2){
      	yesOrNo[i] = 0;
      }
    }

    iteration = 0;
    
    lcd.clear();
    lcd.setCursor(0,0); 			//goto first column and first line (0,0)
    lcd.print("Restarting"); 		//Print at cursor Location 
    lcd.setCursor(0,1); 			//goto first column and first line (0,0)
    lcd.print("Please wait... "); 	//Print at cursor Location 
    delay(2000);

  }
}



	// Functions




// Change button 1 state
void clickButton1() {
  state += 1;								// Change button state

  if (state >2){
    state = 0;
  }
}

// Display question on screen
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

// Get total answers (yes/no)
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