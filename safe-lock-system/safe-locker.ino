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

char *password = "4567";
char *inputKey = "";

int position = 0;
int invalidcount = 1;

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
  
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, HIGH);
}

void loop()
{
    char key = keypad.getKey();
  
  if (key != NO_KEY)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  SAFE  LOCKER  ");
        lcd.setCursor(6, 1);

        for (int i = 0; i <= position; i++)
        {
            lcd.print("*");
            playClickSound();
        }

        if (key == password[position])
        {
            position++;
            if (position == 4)
            {
                unlockdoor();
                position = 0;
            }
        }

        else
        {
            ++invalidcount;
            incorrect();
            position = 0;
        }
        if (invalidcount == 5)
        {
            ++invalidcount;
            torture1();
        }
        if (invalidcount == 8)
        {
            torture2();
        }
    }
    // LOOP ENDS!!!//
}

//*******************************************OPEN THE DOOR FUNCTION!!!!***********************************************//

void unlockdoor()
{
    lcd.setCursor(0, 0);
    lcd.println("   DOOR  OPEN   ");
    lcd.setCursor(0, 1);
    lcd.println("    WELCOME!    ");

  	unlockbuzz();

    for (pos = 180; pos >= 0; pos -= 5) // goes from 180 degrees to 0 degrees
    {
        myservo.write(pos); // tell servo to go to position in variable 'pos'
        delay(5);           // waits 15ms for the servo to reach the position
    }
    delay(2000);

    delay(1000);
    counterbeep();

    delay(1000);

    for (pos = 0; pos <= 180; pos += 5) // goes from 0 degrees to 180 degrees
    {                                   // in steps of 1 degree
        myservo.write(pos);             // tell servo to go to position in variable 'pos'
        delay(15);

        position = 0;

        lcd.clear();
        displayDefaultMessage();
    }
}

//**********************************WRONG CODE FUNCTION*************************************************//

void incorrect()
{
    delay(500);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("CODE");
    lcd.setCursor(6, 0);
    lcd.print("INCORRECT");
    lcd.setCursor(15, 1);
    lcd.println(" ");
    lcd.setCursor(4, 1);
    lcd.println("GET AWAY!!!");

    lcd.setCursor(13, 1);
    lcd.println(" ");
    Serial.println("CODE INCORRECT YOU ARE UNAUTHORIZED");
    digitalWrite(buzz, HIGH);
    delay(3000);
    lcd.clear();
    digitalWrite(buzz, LOW);
    displayDefaultMessage();
}

// sound to key press
void playClickSound()
{
    digitalWrite(buzz, HIGH);
    delay(50);
    digitalWrite(buzz, LOW);
    delay(50);
}

// default message on LCD
void displayDefaultMessage()
{
    lcd.setCursor(0, 0);
    lcd.println("  SAFE  LOCKER  ");
    lcd.setCursor(0, 1);
    lcd.println("    PASSWORD    ");
}

//********************************UNLOCK BUZZ***********************************//
void unlockbuzz()
{

    digitalWrite(buzz, HIGH);
    delay(80);
    digitalWrite(buzz, LOW);
    delay(80);
    digitalWrite(buzz, HIGH);
    delay(80);
    digitalWrite(buzz, LOW);
    delay(200);
    digitalWrite(buzz, HIGH);
    delay(80);
    digitalWrite(buzz, LOW);
    delay(80);
    digitalWrite(buzz, HIGH);
    delay(80);
    digitalWrite(buzz, LOW);
    delay(80);
}

//*******************************COUNTER BEEP*************************************//
void counterbeep()
{
    delay(1200);

    lcd.clear();
    digitalWrite(buzz, HIGH);

    lcd.setCursor(2, 15);
    lcd.println(" ");
    lcd.setCursor(2, 14);
    lcd.println(" ");
    lcd.setCursor(2, 0);
    delay(200);
    lcd.println("GET IN WITHIN:::");

    lcd.setCursor(4, 1);
    lcd.print("5");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN:");
    digitalWrite(buzz, LOW);
    delay(1000);
    // 2
    digitalWrite(buzz, HIGH);
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN:");
    lcd.setCursor(4, 1); // 2
    lcd.print("4");
    delay(100);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN:");
    digitalWrite(buzz, LOW);
    delay(1000);
    // 3
    digitalWrite(buzz, HIGH);
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN:");
    lcd.setCursor(4, 1); // 3
    lcd.print("3");
    delay(100);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN:");
    digitalWrite(buzz, LOW);
    delay(1000);
    // 4
    digitalWrite(buzz, HIGH);
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN:");
    lcd.setCursor(4, 1); // 4
    lcd.print("2");
    delay(100);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN:");
    digitalWrite(buzz, LOW);
    delay(1000);
    //
    digitalWrite(buzz, HIGH);
    lcd.setCursor(4, 1);
    lcd.print("1");
    delay(100);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.println("GET IN WITHIN::");
    digitalWrite(buzz, LOW);
    delay(1000);
    // 5
    digitalWrite(buzz, HIGH);
    delay(40);
    digitalWrite(buzz, LOW);
    delay(40);
    digitalWrite(buzz, HIGH);
    delay(40);
    digitalWrite(buzz, LOW);
    delay(40);
    digitalWrite(buzz, HIGH);
    delay(40);
    digitalWrite(buzz, LOW);
    delay(40);
    digitalWrite(buzz, HIGH);
    delay(40);
    digitalWrite(buzz, LOW);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("RE-LOCKING");
    delay(500);
    lcd.setCursor(12, 0);
    lcd.print(".");
    delay(500);
    lcd.setCursor(13, 0);
    lcd.print(".");
    delay(500);
    lcd.setCursor(14, 0);
    lcd.print(".");
    delay(400);
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("LOCKED!");
    delay(440);
}
//*****************************TORTURE1****************************************//
void torture1()
{
    delay(1000);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("WAIT FOR ");
    lcd.setCursor(5, 1);
    lcd.print("15 SECONDS");
    digitalWrite(buzz, HIGH);
    delay(15000);
    digitalWrite(buzz, LOW);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("LOL..");
    lcd.setCursor(1, 1);
    lcd.print(" HOW WAS THAT??");
    delay(3500);
    lcd.clear();
}
//******************************TORTURE2*****************************************//
void torture2()
{
    delay(1000);
    lcd.setCursor(1, 0);
    lcd.print(" ");
    lcd.setCursor(2, 0);
    lcd.print("EAR DRUMS ARE");
    lcd.setCursor(0, 1);
    lcd.print(" PRECIOUS!! ");
    delay(1500);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print(" WAIT FOR");
    lcd.setCursor(4, 1);
    lcd.print(" 1 MINUTE");
    digitalWrite(buzz, HIGH);
    delay(55000);
    counterbeep();
    lcd.clear();
    digitalWrite(buzz, LOW);
    lcd.setCursor(2, 0);
    lcd.print("WANT ME TO");
    lcd.setCursor(1, 1);
    lcd.print("REDICULE MORE??");
    delay(2500);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Ha Ha Ha Ha");
    delay(1700);
    lcd.clear();
}
