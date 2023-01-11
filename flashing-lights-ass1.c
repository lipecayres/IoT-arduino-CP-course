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



	//
	//               Level 1 
	// Flash slow 3 times and quickly 3 times
	//

/*

void loop()
{
  // Make flash slow three times
	slowBlinkBlueLED(3);

  // Make flash quickly three times
	fastBlinkBlueLED(3);
}  

*/

	//	
	// 			Level 2 
	//   Initials using Morse Code 
	//   dot = 100mS (fast) / hash = 1000mS (slow)
	//
      // Initial | Morse Code
      //    F    | dot - dot - hash - dot
      //    S    | dot - dot - dot
      //    C    | hash - dot - hash - dot
	//

/*
void loop()
{
	// Flash first letter: F ( dot / dot / hash / dot)

  fastBlinkBlueLED(2);
  slowBlinkBlueLED(1); 
  fastBlinkBlueLED(1);
  
  delay(spaceLettersDelay-dotDelay); 


  	// Flash second letter: S (dot / dot / dot)

  fastBlinkBlueLED(3); 

  delay(spaceLettersDelay-dotDelay); 


	// Flash third letter: C (hash / dot / hash / dot)

  slowBlinkBlueLED(1); 
  fastBlinkBlueLED(1); 
  slowBlinkBlueLED(1); 
  fastBlinkBlueLED(1); 

  delay(spaceWordsDelay-dotDelay); 
}

*/

      //
      // Level 3 - Ambulance Flash
      //

/*

void loop()
{
  fastBlinkBlueLED();
  fastBlinkRedLED();
} 

*/


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