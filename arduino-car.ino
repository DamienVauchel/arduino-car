#include "pins_declaration.h"
#include "wheels_motors.h"

void setup() {
  Serial.begin(9600);
  pinMode(RIGHT_REAR, OUTPUT);
  pinMode(RIGHT_FRONT, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
  pinMode(LEFT_REAR, OUTPUT);
  pinMode(LEFT_FRONT, OUTPUT);
  pinMode(LEFT_SPEED, OUTPUT);
}

void loop() {
  goForward();
  goSlower();
  setSpeed(0);
  delay(1000);
  goForward();
  goFaster();
  stop(); 
  delay(2000);
}
