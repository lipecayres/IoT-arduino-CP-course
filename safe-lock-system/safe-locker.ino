#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define redLed 12
#define greenLed 13

// lcd settings
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// servo settings
#define servo 10
Servo myservo;
int pos = 0;

// buzzer
#define buzz 11

// keypad settings
const byte ROWS = 4;
const byte COLS = 4;

char hexakey[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(hexakey), rowPins, colPins, ROWS, COLS);

String password = "4567", inputKey = "";

int position = 0, attempts = 3, validEntry;

void setup()
{
    // buzzer
    pinMode(buzz, OUTPUT);
    // serial monitor
    Serial.begin(9600);
    // servo
    myservo.attach(servo);
    // lcd connection
    lcd.begin(16, 2);
    // initial screen
    displayDefaultMessage();
}

void loop()
{

    // get entry of keyboard
    char key = keypad.getKey();

    // verify if available
    if (key != NO_KEY)
    {

        // get complete attempt password from user

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  SAFE  LOCKER  ");
        lcd.setCursor(6, 1);

        for (int i = 0; i <= position; i++)
        {
            lcd.print("*");
            playKeySound(1);
        }
            inputKey += key;
            position++;
      
      		Serial.println(inputKey);
    }

    while (position >= 4)
    {
        //check password once
      
      for(int i = 0; i<4; i++){
        if (inputKey[i] == password[i]){
        	validEntry++;
          Serial.println(validEntry);
        }
      }
      
      if (validEntry == 4)
      {
        unlockdoor();
        
        position = 0;
        validEntry =0;
        inputKey = "";
        
      } else {
        attempts--;
        failedAttempt();
        
        position = 0;
        validEntry =0;
        inputKey = "";
      }
      displayDefaultMessage();
    }
  
}

// functions:

// unlock device
void unlockdoor()
{
  	// welcome message
    lcd.setCursor(0, 0);
    lcd.println("     WELCOME    ");
    lcd.setCursor(0, 1);
    lcd.println("      GUEST     ");

    playKeySound(3);


    // servo position to open device
    for (pos = 90; pos >= 0; pos -= 5) 
    {
        myservo.write(pos);
        delay(5);
    }

    // time device is open until close again
    delay(5000);

    lockDevice();

    // servo position to close device
    for (pos = 0; pos <= 90; pos += 5) 
    {                                   
        myservo.write(pos);
        delay(15);

        position = 0;

        lcd.clear();
    }
  
      // final lock message
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("     LOCKED     ");
    delay(1000);
}

// failed attempt to unlock device
void failedAttempt()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" WRONG PASSWORD ");
    lcd.setCursor(0, 1);
    lcd.print("   Attempts:");
    lcd.setCursor(13, 1);
    lcd.print(attempts);

    // 3 times sound
    playKeySound(3);
    
  delay(500);
}


// default message on LCD
void displayDefaultMessage()
{
    lcd.setCursor(0, 0);
    lcd.println("  SAFE  LOCKER  ");
    lcd.setCursor(0, 1);
    lcd.println("    PASSWORD    ");
}

// play sound to key press
void playKeySound(int ocurrences)
{
  for (int i = 0;i<ocurrences;i++){
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);  
  }
}

// lock device after some time opened 
void lockDevice()
{
    // regressive counter lock message (upper line)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("   LOCKING IN   ");
	
    // counter lock time -> 5sec (lower line)
  for (int i=5; i>0;i--){
    lcd.setCursor(7, 1);
    lcd.print(i);
	playKeySound(1);
    delay(1000);

    }
    // play wrong attempt sound (4 times key press)
    playKeySound(4);

    // re-locking message (upper line)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   RE-LOCKING   ");

    // display "dot" counter and key sound (lower line)
    for (int i=0; i<4;i++){
        delay(200);
        Serial.print(".");
        lcd.setCursor(6+i, 1);
        lcd.print(".");
        delay(200);
        digitalWrite(buzz, LOW);
    }
}
