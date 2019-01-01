#include "pins_declaration.h"
#include "wheels_motors.h"
#include "bt_module.h"

void setup() {
    Serial.begin(9600);
    
    carSpeed = 150;
    
    pinMode(RIGHT_REAR, OUTPUT);
    pinMode(RIGHT_FRONT, OUTPUT);
    pinMode(RIGHT_SPEED, OUTPUT);
    pinMode(LEFT_REAR, OUTPUT);
    pinMode(LEFT_FRONT, OUTPUT);
    pinMode(LEFT_SPEED, OUTPUT);

    pinMode(BT_LED, OUTPUT);
}

void loop() {
    btActions();
}
