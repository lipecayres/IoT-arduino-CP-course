//
// Assignment 7 - extra
// 200548559 - Felipe Simoes Cayres
//

// Packages
#include <LiquidCrystal.h>


//*************************************************
//* Public Constants
//*************************************************/
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978 
#define REST      0
//**************************
//**************************

// Define pins on Arduino
	//Piezo
#define buzzerPin 8

	// Buttons
#define button1Pin 2
#define button2Pin 3

	// LCD
  LiquidCrystal lcd( 12,11,7,6,5,4); //These pin numbers are hard coded in on the serial backpack board.


// Variables

	// Array of songs

int melody[5][60] = 
{
  {

    // We Wish You a Merry Christmas
  
    NOTE_C5,4, NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
    NOTE_D5,4, NOTE_D5,4, NOTE_D5,4, NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, 
    NOTE_G5,8, NOTE_F5,8, NOTE_E5,4, NOTE_C5,4, NOTE_C5,4, NOTE_A5,4, 
    NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,NOTE_F5,4, NOTE_D5,4, 
    NOTE_C5,8, NOTE_C5,8, NOTE_D5,4, NOTE_G5,4, NOTE_E5,4, NOTE_F5,2
  },
  {

    // Super Mario Bros theme
  

    NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, 
    NOTE_E5,8, NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, NOTE_C5,-4, 
    NOTE_G4,8, REST,4, NOTE_E4,-4,NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, 
    NOTE_A4,4, NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, 
    NOTE_G5,8, REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4
  },
  {

  // Happy Birthday
  
  NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4, NOTE_E4,-2, 
  NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4, NOTE_F4,-2, 
  NOTE_C4,4, NOTE_C4,8, NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, NOTE_E4,-4, 
  NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8, NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
  NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4
 
  },
  {
     // Hedwig's theme fromn the Harry Potter Movies
  
    REST, 2, NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,NOTE_G4, 2, 
    NOTE_D5, 4,NOTE_C5, -2, NOTE_A4, -2,NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_F4, 2, NOTE_GS4, 4, NOTE_D4, -1, NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, 
    NOTE_A4, 4, NOTE_G4, 2, NOTE_D5, 4, NOTE_F5, 2, NOTE_E5, 4, NOTE_DS5, 2, 
    NOTE_B4, 4, NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_CS4, 2, NOTE_B4, 4
  },
  {
  
    // Dart Vader theme (Imperial March) - Star wars 
  
    NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8, NOTE_F5,2, NOTE_C6,2, NOTE_AS5,8, 
    NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, NOTE_AS5,8, NOTE_A5,8, 
    NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, 
    NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8, NOTE_F5,2, NOTE_C6,2,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, NOTE_AS5,8
  }
};

		// Time measure variables

	// Variables to Count time
	double startTime, endTime, idleTime, totalTime;

	// Check if tima started when loop music
	int startCounter = 0;

		// Game choices

	//Begin game
	int beginGameChoise =0;

	// Instructions
	int instructionsChoise = 0;

	// Song to play choosed by user
  	int playThisSong = 0;  //review

    // Stop btn at songs
	int stop0;

		// Display on screen variables
	
	// Final string to display
	String textToDisplay;

	// Variables to convert double to string and add to textToDisplay
	String str1, str2;
	
	// Size check on idleTime number
	int index = 0;

// Setup

void setup() { 
  Serial.begin(9600);
  lcd.begin (16,2); //Initialize the LCD.
  
  pinMode(buzzerPin, OUTPUT);		 	//Setup buzzer pin as an output pin.
  pinMode(button2Pin, INPUT); // initialize the button pin as a input
  
  attachInterrupt(digitalPinToInterrupt(button1Pin), clickButton1, RISING); 	//Setup button1 pin as an input pin.
  attachInterrupt(digitalPinToInterrupt(button2Pin), clickButton2, RISING); 	//Setup button2 pin as an input pin.

}
             

void loop () {
  
	startGame () ;

}





// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------





            //
            //  Functions
            //

// Main function - run to start game
void startGame () {

    intro();
	playGame();
	showScore();
    restartGame();
}

// Visual indroduction to game
void intro() {
    displayText(">>> Welcome <<<       .         ");
    delay(200);
    displayText(">>> Welcome <<<       ..        ");
    delay(200);
    displayText(">>> Welcome <<<       ...       ");
    delay(200);
    displayText(">>> Welcome <<<       ....      ");
    delay(200);
  
  beginGameChoise = 0;
  while (beginGameChoise ==0){
    displayText("    This is:    What's the song?");
    delay(2000);
    if(beginGameChoise !=0) break;
    displayText("   Click next   button to begin");
    delay(2000);
  }
  

  displayText("> Instructions <      -->");
  delay(2000);
  
  instructionsChoise = 0;
  while (instructionsChoise ==0){
    displayText("Pay attention to    the song");
    delay(1000);
    if(instructionsChoise !=0) break;
    displayText("   Press STOP    to pause clock");
    delay(1000);
    if(instructionsChoise !=0) break;
    displayText("     Ready?      Next to START!");
    delay(1000);
  }
}


// Display message before start new song
void beforeSong(){  
  displayText("  Next song...         3");
  delay(500);
  displayText("  Next song...         2");
  delay(500);
  displayText("  Next song...         1");  
}


// Start game
void playGame(){
  for (int i = 0; i<5;i++){

    beforeSong();

    stop0=0;
    while(stop0 ==0){
      displayText("   Playing...    STOP btn to go!"); 
      playSong(i);
    }

    textToDisplay = "Clock stopped!  Time:";

    
    // Covnerting double to string
    str1 = String(idleTime,2); 

    str2 = "";
    index = 0;

    // Check number size and adding number as string in a variable
    if(totalTime <10){
      textToDisplay += " ";
      for (int i=0;i<4;i++){
        str2 += str1[i];
        index = 4;    
      } 
      
  } else {
    textToDisplay += "";
    for (int i=0;i<5;i++){
      str2 += str1[i];
      index = 5;    
    } 
  }

    // Adding string with number to display on screen

    for (int i=0; i<index;i++){
      textToDisplay += str2[i];  
    }
    textToDisplay += "s";

    // Display message on screen
    displayText(textToDisplay); 
    delay(2000);	
  }
}


// Show final score to user

void showScore() {
  String textToDisplay = "   Total time:       ";
  
  
    // Covnerting double to string  
  String str1 = String(totalTime,2); 
  
  String str2 = "";
  index = 0;

  
    // Check number size and adding number as string in a variable
  if(totalTime <10){
    textToDisplay += " ";
    for (int i=0;i<4;i++){
      str2 += str1;
  	  index = 4;    
    } 
  } else {
    str2 = str1;
    index = 5;
  }

    // Adding string with number to display on screen  
  for (int i=0; i<index;i++){
	textToDisplay += str2[i];  
  }
  textToDisplay += "s";

    // Display message on screen 

  displayText("    END GAME");
  delay(500);
  
  stop0=0;
  while (stop0 !=3){
    
    // Score message
    if (stop0 !=3){
    displayText(textToDisplay); 
  	delay(1000);    
    }
    
    // Restart message
    if (stop0 !=3){
    displayText("    Restart?      Press STOP 3x"); 
  	delay(1000);
    }  
}

}

// Restart game function
void restartGame () {  

    displayText("   Restarting         ."); 
    delay(100);
    displayText("   Restarting         .."); 
    delay(100);
    displayText("   Restarting         ..."); 
    delay(100);
    displayText("   Restarting         ...."); 
    delay(100);
  
  // Setting variables as default;
  stop0 = 0;
  beginGameChoise =0;
  instructionsChoise = 0;
  playThisSong = 0; 
  textToDisplay = "";
  index = 0;
  str1 = str2 = "";
  
}

		// LCD 

// Display text on screen
void displayText(String text) {
  String displayUp;
  String displayDown;
  int textSize = text.length();

  for (int i =0; i< textSize; i++){
    if (i<16){
      displayUp += text[i];
    } else {
      displayDown += text[i];
      }
  
  }
  	
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (0,0)
  lcd.print(displayUp); //Print at cursor Location 
  lcd.setCursor(0,1); //goto first column and first line (0,0)
  lcd.print(displayDown); //Print at cursor Location 
  delay(500); 
}



		// Piezo
// Play song

void playSong(int songCode){

  int time = 150;
  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes

  int notes = sizeof(melody[songCode]) / sizeof(melody[songCode][0]) / 2;

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / time;

  int divider = 0, noteDuration = 0;

  if (startCounter == 0){
    
    // star time clock
    startTime = millis(); 
    startCounter = 1;
  }

  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
    
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[songCode][thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    
    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzerPin, melody[songCode][thisNote], noteDuration * 0.9);
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzerPin);

    if(stop0 != 0) {
      endTime = millis();
      idleTime = (endTime - startTime)/1000;
      thisNote = (notes * 2)-2;
      totalTime += idleTime;
      startCounter = 0;
    }
  }
}

	// Buttons

// Change button 1 (Next)
void clickButton1 () {
  beginGameChoise++;
  instructionsChoise++;
}

// Change button 2 (STOP)
void clickButton2 () {
  stop0++;
  
}

