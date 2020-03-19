// Demo the quad alphanumeric display LED backpack kit
// scrolls through every character, then scrolls Serial
// input onto the display

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Ewma.h>

Ewma adcFilter1(0.1);
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();
const int ir_input_pin = A0;

const int pinRangeBottom = 2;
const int pinRangeTop = 6;
int washCount = 0;
int sensorValue = 0;
float duration, distance;
String completionMessage;
void setup() {
  Serial.begin(9600);
  completionMessage = "ALL DONE";
  alpha4.begin(0x70);  // pass in the address
  alpha4.writeDigitRaw(3, 0x0);
  alpha4.writeDigitRaw(0, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(0, 0x0);
  alpha4.writeDigitRaw(1, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(1, 0x0);
  alpha4.writeDigitRaw(2, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(2, 0x0);
  alpha4.writeDigitRaw(3, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);

  alpha4.clear();
  alpha4.writeDisplay();

  alpha4.writeDigitAscii(1, '2');
  alpha4.writeDigitAscii(2, '0');
  alpha4.writeDisplay();

  for (int i = pinRangeBottom; i <= pinRangeTop; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  sensorValue = analogRead(ir_input_pin);
  float filtered1 = adcFilter1.filter(sensorValue);
  if (filtered1 > 200) {
    countUp();
  }
  
  Serial.println(filtered1);
}

void intToDisplay(int i) {
  char segment1 = i / 10;
  int a = i % 10;

  char b[2];

  String str;

  str = String(a);

  str.toCharArray(b, 2);
  alpha4.writeDigitAscii(1, b);
  alpha4.writeDisplay();
  char segment2 = i % 10;


}

void displayCompletionMessage() {
  for (int i = 3; i < completionMessage.length(); i++) {
    alpha4.writeDigitAscii(0, completionMessage.charAt(i - 3));
    alpha4.writeDigitAscii(1, completionMessage.charAt(i - 2));
    alpha4.writeDigitAscii(2, completionMessage.charAt(i - 1));
    alpha4.writeDigitAscii(3, completionMessage.charAt(i));
    alpha4.writeDisplay();
    delay(400);
  }
  delay(4000);
  alpha4.clear();
  alpha4.writeDisplay();
  alpha4.writeDigitAscii(1, '2');
  alpha4.writeDigitAscii(2, '0');
  alpha4.writeDisplay();
}


void countUp() {

  Serial.println("Counting up");
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '9');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '8');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '7');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '6');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '5');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '4');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '3');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '2');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '1');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '0');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitRaw(1, 0x0000);
  alpha4.writeDigitAscii(2, '9');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '8');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '7');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '6');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '5');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '4');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '3');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '2');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '1');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.writeDigitAscii(2, '0');
  alpha4.writeDisplay();
  delay(2000);
  displayCompletionMessage();

}
