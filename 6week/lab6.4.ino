// C++


// import packacge
#include <LiquidCrystal.h>

// pins on arduino
#define btn1 2
#define btn2 3

// LCD settings
LiquidCrystal lcd( 12,11,7,6,5,4);

// name to display
String displayMessage;

// arrays to save questions and answers
String question[5] {"Drink water is  good?", 
                    "The sky is      yellow?", 
                    "Can a duck fly?", 
                    "Bill Gates      founded Amazon?", 
                    "Is Toronto's    winter cold?"};
int answers[5];
int scoreboard[2];

// track question number
int questionNumber;


void setup() {
  
  // initialize LCD
  lcd.begin (16,2);
  
  // initialize btn
  attachInterrupt(digitalPinToInterrupt(btn1), click1, RISING);
  attachInterrupt(digitalPinToInterrupt(btn2), click2, RISING);
  
  Serial.begin(9600);

}

void loop(){


  // display question after press btn using questionNumber track
  for (int i = 0; i <= 5; i++){

    // loop to show question
    while (answers[4] == 0){
      showMessage(question[questionNumber]);
    }
  }


  // iterate answers to get final score
  for (int i=0; i<5;i++){

    // condition to yes (1) or no(2) answer
    if (answers[i] == 1){
      scoreboard[0]++;
    } else if (answers[i] == 2) {
      scoreboard[1]++;
    }

    Serial.println(scoreboard[0]);
    Serial.println(scoreboard[1]);
    Serial.println("-----------");
  }

  // infinite loop to keep showing the score
  int loopLocker = 0;
  while (loopLocker == 0){
    
    // show score
    showMessage("Score:          Yes: " + (String)scoreboard[0] + " // No: " +(String)scoreboard[1] );
  	delay(5000);
  }

}


// change btn1 status
void click1() {
  answers[questionNumber] = 1;
  questionNumber++;
}

// change btn2 status
void click2() {
  answers[questionNumber] = 2;
  questionNumber++;
}

// show message at LCD
void showMessage(String message) {
  // one string to each row
  String top, bottom;
  
  // split string in 2 rows
  for (int i =0, n = message.length(); i< n; i++){
    if (i<16){
      top += message[i];
    } else {
      bottom += message[i];
    }
  }
  
  // display string 
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print(top); 
  lcd.setCursor(0,1); 
  lcd.print(bottom);
  delay(1000); 
}

