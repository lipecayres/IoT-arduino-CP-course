//
// Assignment 7
// 200548559 - Felipe Simoes Cayres
//

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
#define buzzerPin 5
#define button1Pin 2
#define RGBRedPin 9 					//The red RGB LED is connected pin 9 of the Arduino.
#define RGBGreenPin 10 					//The green RGB LED is connected pin 10 of the Arduino.
#define RGBBluePin 11 					//The blue RGB LED is connected pin 11 of the Arduino.


// Variables

	//Array with songs
int melody[3][60] = 
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
     // Hedwig's theme fromn the Harry Potter Movies

    REST, 2, NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,NOTE_G4, 2, 
    NOTE_D5, 4,NOTE_C5, -2, NOTE_A4, -2,NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_F4, 2, NOTE_GS4, 4, NOTE_D4, -1, NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, 
    NOTE_A4, 4, NOTE_G4, 2, NOTE_D5, 4, NOTE_F5, 2, NOTE_E5, 4, NOTE_DS5, 2, 
    NOTE_B4, 4, NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_CS4, 2, NOTE_B4, 4
  },
  {

  // Happy Birthday

  NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4, NOTE_E4,-2, 
  NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4, NOTE_F4,-2, 
  NOTE_C4,4, NOTE_C4,8, NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, NOTE_E4,-4, 
  NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8, NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
  NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8, NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4
 
  }
};

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

	// Song to play
  int playThisSong = 9;


// Setup

void setup() { 
	pinMode(buzzerPin, OUTPUT);		 	//Setup buzzer pin as an output pin.
	pinMode(button1Pin, INPUT); 		//Setup button1 pin as an input pin.
	Serial.begin(9600);
    randomSeed(analogRead(0));
}


      //
      //  Level 2 - Copy inside main loop
      //

/*

void loop() { //The loop function runs forever.
  
  if (digitalRead(button1Pin) == HIGH) { //Check to see if button1 is pressed.
    tone(buzzerPin, NOTE_B4,408);
    delay(408);
    tone(buzzerPin, NOTE_A4,408);
    delay(408);
    tone(buzzerPin, NOTE_G4,408);
    delay(408);
    tone(buzzerPin, NOTE_A4,408);
    delay(408);
    tone(buzzerPin, NOTE_B4,408);
    delay(408);
    tone(buzzerPin, NOTE_B4,408);
    delay(408);
    tone(buzzerPin, NOTE_B4,408);
  }

}

*/
	
      //
      //  Level 3 - Use arrays to store the notes and durations + light show
      //

/*

void loop (){

	//Pick a song randomly
  playThisSong = random(1, 4);

	//Check to see if button1 is pressed.
  if (digitalRead(button1Pin) == HIGH) { 

		//Pick a song randomly
  	playSong(playThisSong); 
    turnOffRGBLED ();
  }
}

*/

    //
	// Level 4 - Menu system
	//

/*

void loop () {

	runMenu();
  
}



*/
            //
            //  Functions
            //


void runMenu() 
{  
	playThisSong = 9;
    Serial.println("-------");
    Serial.println("Choose a song");
    Serial.println("1- Song1 - Christmas");
    Serial.println("2- Song2 - Harry Potter");
    Serial.println("3- Song3 - Happy Birthday");
    Serial.println("-------");
    
  while (playThisSong == 9){

    if (Serial.available()) {
      //Read typed characters 
      int pickSong = Serial.read();
      
      if (pickSong == '1'){
      	playThisSong = 0;
      } else if (pickSong == '2'){
        playThisSong = 1;
      }else if (pickSong == '3'){
        playThisSong = 2;
      } else {
        pickSong = Serial.read();
      }
    }
  }
  
	playSong(playThisSong);
	turnOffRGBLED ();
}


// Play song

void playSong(int songCode){

  int time = 150;
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

    //

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    
    // stop the waveform generation before the next note.
    noTone(buzzerPin);

    turnOnLEDByRGB(random(0, 255),random(0, 255),random(0, 255));
  }
}


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