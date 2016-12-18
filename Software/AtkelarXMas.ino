/*

  Atkelar's Christmas Entanglement

  Copyright 2016 by Atkelar

  License: Apache License, Version 2.0

*/

#include "avr/pgmspace.h"
// We need a tad bit more space for the blink-pattern table so 
// we use the program space library and read back the data on-the-go.

// The LED port defaults are: 9 and 10 for PWM output, 2 to 6 for digital.
// The defaults keep pin 0 and 1 free to have 
// debugging TX/RX available if needed.

#define ledPWM1 9
#define ledPWM2 10

#define led0 2
#define led1 3
#define led2 4
#define led3 5
#define led4 6

// The number of steps in the array. Could be calculated by length-of-data / 8.
#define STEPS 165

// The actual light info. To keep the loop simple, we use one byte per pin
// Version 2 would benefit from a structure with bits for digital outputs
// compressed into bit pattern. That way we could *maybe* get away without
// the progmem library. But the pattern generator would be more complicated.
// Pattern data is: 5 digital ports followed by 2 analog ports followed by
// the delay value. The actual loop delay might be slightly larger because
// of all the reading/writing overhead but should be neglectable in MHz clocks.
const byte data[] PROGMEM = {
  LOW, HIGH, HIGH, HIGH, HIGH, 191, 102, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 179, 102, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 166, 102, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 153, 102, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 141, 102, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 128, 102, 50,
  LOW, HIGH, HIGH, HIGH, HIGH, 128, 102, 20,
  LOW, HIGH, HIGH, HIGH, HIGH, 145, 102, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 162, 102, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 179, 102, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 196, 94, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 213, 85, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 230, 76, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 230, 68, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 230, 60, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 230, 51, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 230, 42, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 230, 34, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 230, 26, 10,
  LOW, LOW, HIGH, HIGH, HIGH, 230, 17, 10,
  HIGH, LOW, HIGH, HIGH, HIGH, 230, 8, 10,
  HIGH, LOW, HIGH, HIGH, HIGH, 230, 0, 40,
  HIGH, LOW, LOW, HIGH, HIGH, 230, 0, 60,
  HIGH, LOW, LOW, LOW, HIGH, 196, 0, 10,
  HIGH, LOW, LOW, LOW, HIGH, 162, 0, 10,
  HIGH, LOW, LOW, LOW, HIGH, 128, 0, 10,
  HIGH, LOW, LOW, LOW, HIGH, 94, 0, 10,
  LOW, LOW, LOW, LOW, HIGH, 60, 0, 10,
  LOW, LOW, LOW, LOW, HIGH, 26, 0, 40,
  LOW, LOW, LOW, LOW, HIGH, 26, 2, 10,
  LOW, LOW, LOW, LOW, HIGH, 26, 4, 10,
  LOW, LOW, LOW, LOW, HIGH, 26, 6, 10,
  LOW, HIGH, LOW, LOW, HIGH, 26, 9, 10,
  LOW, HIGH, LOW, LOW, HIGH, 26, 11, 10,
  LOW, HIGH, LOW, LOW, HIGH, 26, 13, 10,
  LOW, HIGH, LOW, LOW, HIGH, 30, 15, 10,
  LOW, HIGH, LOW, LOW, HIGH, 34, 17, 10,
  LOW, HIGH, LOW, LOW, HIGH, 38, 20, 10,
  LOW, HIGH, LOW, LOW, LOW, 43, 22, 10,
  HIGH, HIGH, LOW, LOW, LOW, 47, 24, 10,
  HIGH, HIGH, LOW, LOW, LOW, 51, 26, 40,
  LOW, HIGH, LOW, LOW, LOW, 51, 26, 30,
  LOW, HIGH, LOW, HIGH, LOW, 85, 26, 10,
  LOW, HIGH, LOW, HIGH, LOW, 119, 26, 10,
  LOW, HIGH, LOW, HIGH, LOW, 153, 26, 10,
  LOW, HIGH, LOW, HIGH, LOW, 187, 26, 10,
  LOW, HIGH, LOW, HIGH, LOW, 221, 26, 10,
  LOW, HIGH, LOW, HIGH, LOW, 255, 26, 40,
  LOW, LOW, HIGH, HIGH, LOW, 255, 26, 30,
  HIGH, LOW, HIGH, HIGH, LOW, 225, 26, 10,
  HIGH, LOW, HIGH, HIGH, LOW, 195, 26, 10,
  HIGH, LOW, HIGH, HIGH, LOW, 165, 26, 10,
  HIGH, LOW, HIGH, HIGH, LOW, 136, 26, 10,
  HIGH, LOW, HIGH, HIGH, LOW, 106, 26, 10,
  LOW, LOW, HIGH, HIGH, LOW, 76, 26, 40,
  LOW, LOW, HIGH, HIGH, LOW, 76, 41, 10,
  LOW, LOW, HIGH, HIGH, LOW, 76, 56, 10,
  LOW, LOW, HIGH, HIGH, LOW, 76, 70, 10,
  LOW, LOW, HIGH, HIGH, LOW, 93, 85, 10,
  LOW, LOW, HIGH, HIGH, LOW, 110, 100, 10,
  LOW, LOW, HIGH, HIGH, LOW, 127, 115, 10,
  LOW, LOW, HIGH, LOW, LOW, 144, 130, 10,
  LOW, LOW, HIGH, LOW, LOW, 161, 145, 10,
  LOW, LOW, HIGH, LOW, LOW, 178, 160, 10,
  LOW, HIGH, HIGH, LOW, LOW, 178, 174, 10,
  LOW, HIGH, HIGH, LOW, LOW, 178, 189, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 178, 204, 10,
  HIGH, HIGH, LOW, LOW, LOW, 157, 204, 10,
  HIGH, HIGH, LOW, LOW, LOW, 136, 204, 10,
  HIGH, HIGH, LOW, LOW, LOW, 115, 204, 10,
  HIGH, HIGH, LOW, LOW, HIGH, 93, 204, 10,
  HIGH, HIGH, LOW, LOW, HIGH, 72, 204, 10,
  HIGH, HIGH, LOW, LOW, HIGH, 51, 204, 70,
  HIGH, HIGH, LOW, LOW, HIGH, 64, 204, 10,
  HIGH, HIGH, LOW, LOW, HIGH, 77, 204, 10,
  LOW, HIGH, LOW, LOW, HIGH, 90, 204, 10,
  LOW, HIGH, LOW, LOW, HIGH, 102, 204, 10,
  LOW, HIGH, LOW, LOW, HIGH, 115, 204, 10,
  LOW, HIGH, LOW, LOW, HIGH, 128, 204, 10,
  LOW, LOW, HIGH, LOW, HIGH, 128, 204, 10,
  HIGH, LOW, HIGH, LOW, HIGH, 128, 204, 20,
  HIGH, LOW, HIGH, HIGH, HIGH, 128, 204, 30,
  LOW, LOW, HIGH, HIGH, HIGH, 128, 204, 30,
  LOW, LOW, HIGH, HIGH, HIGH, 128, 196, 10,
  LOW, LOW, HIGH, HIGH, HIGH, 128, 187, 10,
  HIGH, LOW, HIGH, HIGH, HIGH, 128, 178, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 111, 170, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 94, 162, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 77, 153, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 60, 144, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 43, 136, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 26, 128, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 26, 119, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 26, 110, 10,
  LOW, HIGH, HIGH, HIGH, HIGH, 26, 102, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 26, 102, 30,
  HIGH, LOW, HIGH, HIGH, HIGH, 34, 102, 10,
  HIGH, LOW, HIGH, HIGH, HIGH, 43, 102, 10,
  HIGH, LOW, HIGH, HIGH, HIGH, 51, 102, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 59, 102, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 68, 102, 10,
  HIGH, HIGH, HIGH, HIGH, HIGH, 76, 102, 10,
  HIGH, HIGH, HIGH, HIGH, LOW, 76, 102, 30,
  HIGH, HIGH, HIGH, HIGH, LOW, 93, 102, 10,
  HIGH, HIGH, HIGH, HIGH, LOW, 110, 102, 10,
  HIGH, HIGH, HIGH, HIGH, LOW, 127, 102, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 144, 102, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 161, 102, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 178, 102, 40,
  HIGH, HIGH, LOW, HIGH, LOW, 178, 98, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 178, 94, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 178, 89, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 178, 85, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 178, 81, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 178, 76, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 161, 72, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 144, 68, 10,
  HIGH, HIGH, LOW, HIGH, LOW, 127, 64, 10,
  HIGH, LOW, LOW, HIGH, LOW, 110, 60, 10,
  HIGH, LOW, LOW, HIGH, LOW, 93, 55, 10,
  HIGH, LOW, LOW, HIGH, LOW, 76, 51, 70,
  HIGH, HIGH, LOW, HIGH, LOW, 76, 51, 60,
  HIGH, HIGH, LOW, LOW, LOW, 76, 51, 30,
  HIGH, HIGH, LOW, LOW, LOW, 93, 51, 10,
  HIGH, HIGH, LOW, LOW, LOW, 110, 51, 10,
  HIGH, HIGH, LOW, LOW, LOW, 127, 51, 10,
  HIGH, HIGH, LOW, LOW, LOW, 144, 51, 10,
  HIGH, HIGH, LOW, LOW, LOW, 161, 51, 10,
  HIGH, HIGH, LOW, LOW, LOW, 178, 51, 10,
  HIGH, HIGH, LOW, LOW, LOW, 178, 68, 10,
  HIGH, HIGH, LOW, LOW, LOW, 178, 85, 10,
  HIGH, HIGH, LOW, LOW, LOW, 178, 102, 10,
  HIGH, HIGH, LOW, LOW, LOW, 148, 119, 10,
  HIGH, HIGH, LOW, LOW, LOW, 119, 136, 10,
  HIGH, HIGH, LOW, LOW, LOW, 89, 153, 10,
  HIGH, HIGH, LOW, LOW, LOW, 59, 170, 10,
  HIGH, HIGH, LOW, LOW, LOW, 30, 187, 10,
  HIGH, HIGH, LOW, LOW, LOW, 0, 204, 10,
  HIGH, LOW, HIGH, LOW, LOW, 0, 221, 10,
  HIGH, LOW, HIGH, LOW, LOW, 0, 238, 10,
  HIGH, LOW, HIGH, LOW, LOW, 0, 255, 70,
  HIGH, LOW, HIGH, LOW, LOW, 21, 255, 10,
  HIGH, LOW, HIGH, LOW, LOW, 43, 255, 10,
  HIGH, LOW, HIGH, LOW, LOW, 64, 255, 10,
  HIGH, LOW, HIGH, LOW, LOW, 85, 255, 10,
  HIGH, LOW, HIGH, LOW, LOW, 107, 255, 10,
  HIGH, LOW, HIGH, LOW, LOW, 128, 255, 70,
  HIGH, LOW, HIGH, LOW, LOW, 132, 255, 10,
  HIGH, LOW, HIGH, LOW, LOW, 136, 255, 10,
  HIGH, LOW, HIGH, LOW, LOW, 140, 255, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 145, 255, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 149, 255, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 153, 255, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 153, 242, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 153, 230, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 153, 217, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 153, 204, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 153, 191, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 153, 178, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 162, 166, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 170, 153, 10,
  HIGH, HIGH, HIGH, LOW, LOW, 178, 140, 10,
  HIGH, LOW, HIGH, LOW, LOW, 187, 128, 10,
  HIGH, LOW, HIGH, LOW, LOW, 196, 115, 10,
  HIGH, LOW, HIGH, LOW, LOW, 204, 102, 160
 };

// The current step in the pattern.
int loopIndex = 0;

// Set up our output pins
void setup() {
  pinMode(ledPWM1, OUTPUT);
  pinMode(ledPWM2, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {

  // start the loop by showing the current index:
  int offset = loopIndex * 8;  // Current offset into the data array.

  // read and advance offset, the temp variable 'x' eases debugging
  int x = pgm_read_byte_near(data + offset++);
  digitalWrite(led0, x);

  x = pgm_read_byte_near(data + offset++);
  digitalWrite(led1, x);
  x = pgm_read_byte_near(data + offset++);
  digitalWrite(led2, x);
  x = pgm_read_byte_near(data + offset++);
  digitalWrite(led3, x);
  x = pgm_read_byte_near(data + offset++);
  digitalWrite(led4, x);

  x = pgm_read_byte_near(data + offset++);
  analogWrite(ledPWM1, x);
  x = pgm_read_byte_near(data + offset++);
  analogWrite(ledPWM2, x);

  x = pgm_read_byte_near(data + offset++);
  delay(x);

  // Step up and loop around if we are beyond our realm.
  loopIndex++;
  if (loopIndex >= STEPS)
    loopIndex = 0;
}

