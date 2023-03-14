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

  int melody[3][24] {
{
  NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_D3,
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_E3, 0,
  NOTE_E3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_FS3, 0 ,
  NOTE_D4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_B3
},
{
  REST, NOTE_D4, NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_F4, NOTE_GS4, NOTE_D4,NOTE_D4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_F5, NOTE_E5,
  NOTE_DS5
},
{

  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, 
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, 
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, 
  NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4
}};

  int noteDurations[3][24] 
{
  {4, 4, 4, 4, 2.5, 8, 8, 4, 4, 4, 4, 2.5, 
    2, 4, 4, 4, 4, 2.5, 2, 4, 4, 4, 4, 1
  },
  {2, 4, 4, 8, 4, 2, 4, 2, 2, 4, 8, 4, 
    2, 4, 1, 4, 4, 8, 4,2, 4, 2, 4, 2
  },
  {4,8,4,4,4,2,4,8,4,4,4,2,
    4,8,4,4,4,4,4,4,8,4,4,2
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

// Setup

void setup() { 
	pinMode(buzzerPin, OUTPUT);		 	//Setup buzzer pin as an output pin.
	pinMode(button1Pin, INPUT); 		//Setup button1 pin as an input pin.
	Serial.begin(9600);
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

int melody1[] = {
  NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_D3,
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_E3, 0,
  NOTE_E3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_FS3, 0 ,
  NOTE_D4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_B3
};

int noteDurations1[] = {
  4, 4, 4, 4, 2.5,
  8, 8, 4, 4, 4, 4, 2.5, 2,
  4, 4, 4, 4, 2.5, 2,
  4, 4, 4, 4, 1};


void loop (){

  if (digitalRead(button1Pin) == HIGH) { //Check to see if button1 is pressed.
    for (int i = 0; i<sizeof(melody1)/2; i++){
      Serial.println(noteDurations1[i]);
      ledsShow(noteDurations1[i]);
      tone(buzzerPin, melody1[i],noteDurations1[i]*1000);
      delay(200);
      turnOffRGBLED ();
      delay(100);
    }
      ledsShow(noteDurations1[24]);
      delay(1000);
      turnOffRGBLED ();
  }
         
}


*/


	//
	// Level 4
	//


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





void loop () {
	runMenu();
  
}






            //
            //  Functions
            //

void runMenu() {
	              
  	int playThisSong = 0;
    unsigned long delay1 = 0;	 // Delay to input sequence
  
    Serial.println("-------");
    Serial.println("Choose a song");
    Serial.println("1- Song1 - Christmas 1");
    Serial.println("2- Song2 - Christmas 2");
    Serial.println("3- Song3 - Happy Birthday");
    Serial.println("-------");
    
  while (playThisSong== 0){
	  if (Serial.available()) {
    	//Read typed characters 
    	playThisSong = Serial.read();
  }
    
    switch (playThisSong) {

    case '1':
      Serial.println("Playing: Christmas 1");
      playSong1();
      break;

    case '2':
      Serial.println("Playing: Christmas 2");
      playSong2();
      break;

    case '3':
      Serial.println("Playing: Happy Birthday");      
      playSong3();
      break;  

    }
  }
}

// Play song 1
void playSong1 () {
  
  	// Christmas song
  
  int melody[] = {
  NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_D3,
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_E3, 0,
  NOTE_E3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_FS3, 0 ,
  NOTE_D4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_B3
};

int noteDurations[] = {
  4, 4, 4, 4, 2.5,
  8, 8, 4, 4, 4, 4, 2.5, 2,
  4, 4, 4, 4, 2.5, 2,
  4, 4, 4, 4, 1
};
  
  for (int i = 0; i<sizeof(melody)/2; i++){
    ledsShow(noteDurations[i]);
    tone(buzzerPin, melody[i],noteDurations[i]*1000);
    delay(200);
	turnOffRGBLED ();
    delay(100);
  }
    ledsShow(noteDurations[24]);
    delay(1000);
	turnOffRGBLED ();

}


// Play song 2
void playSong2 () {
 
 	 // Christmas 2
  
  int melody[] = {
  NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C3, NOTE_AS3, NOTE_A3, NOTE_G3, NOTE_F3,
  NOTE_C4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_F4
};
  
  int noteDurations[] = {
  2, 2.5, 8, 1.5, 4, 2, 2 ,1.5,
  4, 1.8, 4, 1.8, 4, 1
  };
    
  for (int i = 0; i<sizeof(melody)/2; i++){
    ledsShow(noteDurations[i]);
    tone(buzzerPin, melody[i],noteDurations[i]*1000);
    delay(200);
	turnOffRGBLED ();
    delay(100);
  }
    ledsShow(noteDurations[24]);
    delay(1000);
	turnOffRGBLED ();
}
  
void playSong3 () {

    // Happy Birthday
  
  int melody[] = {

  NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_C4, NOTE_C4,

  NOTE_C5, NOTE_A4, NOTE_F4, 
  NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_F4, NOTE_G4,
};
  
int noteDurations[] = {
  4,8,
  4,4,4,
  2,4,8,
  4,4,4,
  2,4,8,
  4,4,4,
  4,4,4,8,
  4,4,2
};
  
  for (int i = 0; i<sizeof(melody)/2; i++){
    ledsShow(noteDurations[i]);
    tone(buzzerPin, melody[i],noteDurations[i]*1000);
    delay(200);
	turnOffRGBLED ();
    delay(100);
  }
    ledsShow(noteDurations[24]);
    delay(2000);
	turnOffRGBLED ();
}


// leds uhu
void ledsShow(double note) {
  int color = 0;
  
  if(note ==1){
    color = 1;
    } else if (note <2){
      color = 2;
    } else if (note ==2){
      color = 3;
    } else if (note =2.5){
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