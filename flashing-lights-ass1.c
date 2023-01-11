//
// Assignment 1
// 200548559 - Felipe Simoes Cayres
//

// Variables
	
	// LED indication
int blueLED = 13; 
int redLED = 11;

	// Morse code pattern time(mS)
int dotDelay = 100; 
int dashDelay = 1000;
int spaceLettersDelay = 3*dotDelay; // three units
int spaceWordsDelay = 7 * dotDelay; // seven units

// Prototypes

void fastBlinkBlueLED (int times);
void slowBlinkBlueLED (int times);
void fastBlinkRedLED (int times);
void slowBlinkRedLED (int times);

// Setup

void setup()
{
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}




// Funtions

	// BLINK BLUE LED

void fastBlinkBlueLED (int times) // Blink Blue LED FAST
{
  for (int i = 0; i <times; i++) {
    digitalWrite(blueLED, HIGH);
    delay(dotDelay);
    digitalWrite(blueLED, LOW);
    delay(dotDelay);
  }
    return;
}


void slowBlinkBlueLED (int times) // Blink blue LED SLOW
{
  for (int i = 0; i <times; i++) {
    digitalWrite(blueLED, HIGH);
    delay(dashDelay); 
    digitalWrite(blueLED, LOW);
    delay(dashDelay);   
  }
  return;
}

	// RED LED

void fastBlinkRedLED (int times) // Blink Red LED FAST
{
  for (int i = 0; i < times; i++) {
    digitalWrite(redLED, HIGH);
    delay(dotDelay); 
    digitalWrite(redLED, LOW);
    delay(dotDelay);   
    }

  return; 
}

void slowBlinkRedLED (int times) // Blink red LED SLOW
{
  for (int i = 0; i < times; i++) {
    digitalWrite(redLED, HIGH);
    delay(dashDelay); 
    digitalWrite(redLED, LOW);
    delay(dashDelay); 
  }
    return;
}