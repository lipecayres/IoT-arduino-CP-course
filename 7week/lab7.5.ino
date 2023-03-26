// C++
//Name: Jessica Nayara Pereira
//Date: Mar 21, 2023

//*************************************************
//* Public Constants
//*************************************************/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


int melody[5][50] = {

  // Pink Panther theme
  {
    REST,2, REST,4, REST,8, NOTE_DS4,8, 
    NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
    NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
    NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
    NOTE_E4,2 
  },
  {

    // Game of Thrones

    NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, //1
    NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16,
    NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
    NOTE_G4,8 
  },
  {

    // Pacman

    NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, //1
    NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
    NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,

    NOTE_B4, 16,  NOTE_B5, 16,  NOTE_FS5, 16,   NOTE_DS5, 16,  NOTE_B5, 32,  //2
    NOTE_FS5, -16, NOTE_DS5, 8,  NOTE_DS5, 32, NOTE_E5, 32,  NOTE_F5, 32,
    NOTE_F5, 32
  },
  {

    // Jigglypuff's Song

    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    NOTE_FS5,-4, NOTE_E5,8, NOTE_FS5,4,
    NOTE_D5,-2,
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    NOTE_FS5,-1,
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8

  },
  {

    // Happy Birthday

    NOTE_C4,4, NOTE_C4,8, 
    NOTE_D4,-4, NOTE_C4,-4, NOTE_F4,-4,
    NOTE_E4,-2, NOTE_C4,4, NOTE_C4,8, 
    NOTE_D4,-4, NOTE_C4,-4, NOTE_G4,-4,
    NOTE_F4,-2, NOTE_C4,4, NOTE_C4,8,

    NOTE_C5,-4, NOTE_A4,-4, NOTE_F4,-4, 
    NOTE_E4,-4, NOTE_D4,-4, NOTE_AS4,4, NOTE_AS4,8,
    NOTE_A4,-4, NOTE_F4,-4, NOTE_G4,-4,
    NOTE_F4,-2,

  }
};

int timeDurations[5] = {120,85,105, 85 ,140};

// circuit pins
#define redPin 12 
#define greenPin 10
#define bluePin 11

#define buzzerPin 5
#define btnPin 2

// music speed
int time; 

// music reference number
int stopMusic;


// time variables
double startTime,endTime, guessTime, totalTime, runCronometer;

void setup() { 
  
  // pins setup
  pinMode(buzzerPin, OUTPUT); 

  attachInterrupt(digitalPinToInterrupt(btnPin), btn, RISING);
  Serial.begin(9600);  
}



void loop() {

  // start program
  runMenu();

}




// menu choices
void runMenu() {

  Serial.println("Press stop when you know the music:");
    
  for (int i = 0; i<5;i++){
    // quick delay to start music
    delay(500);
    
    // get time music speed
	time = timeDurations[i];
	
    Serial.println("Playing music...");
    
    // play music while btn isn't pressed
    stopMusic = 0;
    while (stopMusic ==0){
    	playMusic(i);
    }
    
    // partial time score
    Serial.println("STOP!");
    Serial.println("Time to guess: ");
    Serial.print(guessTime);
    Serial.println("");
    Serial.println("--------");
    
    delay(1000);
  }
  
  // final time score
  Serial.println("FINISH!");
  Serial.println("Total time: ");
  Serial.print(totalTime);
  Serial.println("");
  Serial.println("--------");

  // infinite loop to prevent running again
  while (stopMusic == 9){
	delay(5000);

  }
}

// play song 
void playMusic(int numberMusic) {

  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  int notes = sizeof(melody[numberMusic]) / sizeof(melody[numberMusic][0]) / 2;

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / time;
  int divider = 0, noteDuration = 0;

  // start cronometer
  // run once in a loop

  if (runCronometer == 0){  
    startTime = millis(); 
    runCronometer = 9;
  } 


  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[numberMusic][thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzerPin, melody[numberMusic][thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzerPin);

    // check if stop btn pressed
    if(stopMusic == 9) {
      // stop clock
      endTime = millis();
      //get time
      guessTime = (endTime - startTime)/1000;
      totalTime += guessTime;
      // go to last note (stop music)
      thisNote = (notes * 2)-2;
      // allow next music to play
      runCronometer = 0;
    }
  }
}

// button click
void btn () {

  // stop music
  stopMusic = 9;

}

