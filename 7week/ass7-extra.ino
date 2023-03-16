//
// Assignment 7
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

	// RGB LED
#define RGBRedPin 9 					//The red RGB LED is connected pin 9 of the Arduino.
#define RGBGreenPin 13 					//The green RGB LED is connected pin 13 of the Arduino.
#define RGBBluePin 10 					//The blue RGB LED is connected pin 10 of the Arduino.


// Variables


	// Array with ROYGBP colors
  int colors[6][3] = {
    {255,0,0}, 			// red
    {255,165,0}, 		// orange
    {255,255,0},		// yellow
    {0,255,0},			// green
    {0,0,255},			// blue
    {128,0,128} 		// purple
  };  

	//Size of colors array
  int colorsSize = sizeof(colors)/sizeof(colors[0]);


	// Array of songs

int melody[5][60] = 
{
  {

    // We Wish You a Merry Christmas
    // Score available at https://musescore.com/user/6208766/scores/1497501

    NOTE_C5,4, NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
    NOTE_D5,4, NOTE_D5,4, NOTE_D5,4, NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, 
    NOTE_G5,8, NOTE_F5,8, NOTE_E5,4, NOTE_C5,4, NOTE_C5,4, NOTE_A5,4, 
    NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,NOTE_F5,4, NOTE_D5,4, 
    NOTE_C5,8, NOTE_C5,8, NOTE_D5,4, NOTE_G5,4, NOTE_E5,4, NOTE_F5,2
  },
  {

    // Super Mario Bros theme
    // Score available at https://musescore.com/user/2123/scores/2145
    // Theme by Koji Kondo


    NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, 
    NOTE_E5,8, NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, NOTE_C5,-4, 
    NOTE_G4,8, REST,4, NOTE_E4,-4,NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, 
    NOTE_A4,4, NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, 
    NOTE_G5,8, REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4
  },
  {

  // Happy Birthday
  // Score available at https://musescore.com/user/8221/scores/26906

  NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4, NOTE_E4,-2, 
  NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4, NOTE_F4,-2, 
  NOTE_C4,4, NOTE_C4,8, NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, NOTE_E4,-4, 
  NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8, NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
  NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4
 
  },
  {
     // Hedwig's theme fromn the Harry Potter Movies
    // Socre from https://musescore.com/user/3811306/scores/4906610

    REST, 2, NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,NOTE_G4, 2, 
    NOTE_D5, 4,NOTE_C5, -2, NOTE_A4, -2,NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_F4, 2, NOTE_GS4, 4, NOTE_D4, -1, NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, 
    NOTE_A4, 4, NOTE_G4, 2, NOTE_D5, 4, NOTE_F5, 2, NOTE_E5, 4, NOTE_DS5, 2, 
    NOTE_B4, 4, NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_CS4, 2, NOTE_B4, 4
  },
  {
  
    // Dart Vader theme (Imperial March) - Star wars 
    // Score available at https://musescore.com/user/202909/scores/1141521
    // The tenor saxophone part was used

    NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8, NOTE_F5,2, NOTE_C6,2, NOTE_AS5,8, 
    NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, NOTE_AS5,8, NOTE_A5,8, 
    NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, 
    NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8, NOTE_F5,2, NOTE_C6,2,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, NOTE_AS5,8
  }
};

		// Answers
	String melodyNames[5] = {"Merry Christmas","Mario Bros theme", "Happy Birthday","Hedwig's theme","Dart Vader theme"};
    double melodyTimes[5] = {0,0,0,0,0};
    int yesOrNoAnswers[2] = {0,0};

		// Time variables
	double startTimeSong, endTimeSong;

		// Game choices

	//Begin game
	int beginGameChoise =0;

	// Instructions
	int instructionsChoise = 0;

	// Song to play choosed by user
  	int playThisSong = 0;  //review

    // Stop btn at songs
	int stop0,stop1,stop2,stop3,stop4;

int buttonState = 0;     // current state of the button
int lastButtonState = 0; // previous state of the button
int startPressed = 0;    // the moment the button was pressed
int endPressed = 0;      // the moment the button was released
int holdTime = 0;        // how long the button was hold
int idleTime = 0;        // how long the button was idle

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

  int time1 = millis();
  Serial.println(time1);
  delay(2000);
    Serial.println(time1);
  delay(2000);
  int time2 = millis();
  Serial.println(time1);
      Serial.println(time2);
  delay(2000);
      Serial.println(time1);
    Serial.println(time2);
  delay(2000);
  
  /*
  	intro();
    
  displayText("    Song 1             3");
  delay(500);
  displayText("    Song 1             2");
  delay(500);
  displayText("    Song 1             1");  
  
  stop0=0;
  
  while(stop0 ==0){
    displayText("   Playing...    STOP btn to go!"); 
    playSong(0);
  }  

  */

}

 // playSong(3);
















// ---------------------------------------------------








            //
            //  Functions
            //

void intro() {
    displayText(">>> Welcome <<<");
    delay(2000);
  
  
  while (beginGameChoise ==0){
    displayText("    This is     What's the song?");
    delay(1000);
    if(beginGameChoise !=0) break;
    displayText("   Click next   button to begin");
    delay(1000);
  }
  
  instructionsChoise = 0;
  displayText("> Instructions <");
  delay(2000);
  
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

void runMenu() 
{  
	playThisSong = 9;
    Serial.println("-------");
    Serial.println("Choose a song");
    Serial.println("1- Song1 - Christmas");
    Serial.println("2- Song2 - Harry Potter");
    Serial.println("3- Song3 - Happy Birthday");
    Serial.println("-------");


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

  int time = 170;
  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  
  int notes = sizeof(melody[songCode]) / sizeof(melody[songCode][0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / time;

int divider = 0, noteDuration = 0;

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
    if(thisNote<0){
	    ledsShow(thisNote *(-1));
    } else {
    	ledsShow(thisNote);
    }
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzerPin);
  }
}

// LED's show while songs are on
void ledsShow(double note) {
  int color = 0;
  
  if(note ==1){
    color = 1;
    } else if (note <2){
      color = 2;
    } else if (note ==2){
      color = 3;
    } else if (note ==2.5){
      color = 4;
    } else if (note <=4){
      color = 5;
    } else if (note <=8){
      color = 6;
    } else {
      color = 1;
    }
                
  turnOnLEDByRGB (colors[color][0], colors[color][1],colors[color][2]);
}          

	// RGB LED

// Turn On led using RGB CODE
void turnOnLEDByRGB (int red, int green, int blue){
  analogWrite(RGBRedPin, red); 							//Turn on RGB RED
  analogWrite(RGBGreenPin, green);						//Turn on RGB GREEN
  analogWrite(RGBBluePin, blue); 						//Turn on RGB BLUE
}

// Turn off RGB LED
void turnOffRGBLED () {
  analogWrite(RGBRedPin, LOW); 							//Turn off RGB RED
  analogWrite(RGBBluePin, LOW); 						//Turn off RGB BLUE
  analogWrite(RGBGreenPin, LOW);						//Turn off RGB GREEN
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
  stop1++;
  stop2++;
  stop3++;
  stop4++;
  
}

