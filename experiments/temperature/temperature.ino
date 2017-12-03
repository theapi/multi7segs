/*
  Reading a serial ASCII-encoded string.

 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.

 Circuit: Common-Cathode RGB LED wired like so:
 * Red anode: digital pin 3
 * Green anode: digital pin 5
 * Blue anode: digital pin 6
 * Cathode : GND

 created 13 Apr 2012
 by Tom Igoe
 
 modified 14 Mar 2016
 by Arturo Guadalupi

 This example code is in the public domain.
 */

// pins for the LEDs:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  // initialize serial:
  Serial.begin(115200);

  displayTemperature(9.5);

}

void loop() {

}


void displayTemperature(float f) {
  int tens = 10;
  int ones = 0;
  int decimal = 0;


  // Tens
  Serial.print("tens: ");
  if (f >= 10 || f <= -10) {
    tens = (int) f / 10;
    Serial.print(abs(tens));
    //display.setDigitToNumber((block * 4), abs(tens));
  } else if (f < 0) { 
    Serial.print(" negative ");
    // NB temperatures less than minus 10 degrees will not have the negative symbol.
    //display.setDigit((block * 4), display.hyphen);
  } else {
    //display.setDigitToNumber((block * 4), 10);
  }

  // Ones, with a decimal point.
  Serial.print("  ones: ");
  ones = (int) f % 10, 1;
  Serial.print(abs(ones));
  //display.setDigitToNumber((block * 4) - 1, abs(ones), 1);

  // Decimal
  Serial.print("  decimal: ");
  int fraction = (f * 10) ;
  decimal = fraction % 10;
  Serial.print(abs(decimal));
  //display.setDigitToNumber((block * 4) - 2, abs(decimal));
  
  // Show degrees symbol.
  //display.setDigit((block * 4) - 3, display.degrees);

  Serial.println();
}






