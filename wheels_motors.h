unsigned char carSpeed;

void enableWheelsMotors() {
    digitalWrite(RIGHT_SPEED, HIGH);
    digitalWrite(LEFT_SPEED, HIGH);
}

void disableWheelsMotors() {
    digitalWrite(RIGHT_SPEED, LOW);
    digitalWrite(LEFT_SPEED, LOW);
}

void setSpeed(int speed) {
    analogWrite(RIGHT_SPEED, speed);
    analogWrite(LEFT_SPEED, speed);
}

// Directions
void leftWheelsGoForward() {
    digitalWrite(LEFT_REAR, HIGH);
    digitalWrite(LEFT_FRONT, LOW);
}

void rightWheelsGoForward() {
    digitalWrite(RIGHT_REAR, LOW);
    digitalWrite(RIGHT_FRONT, HIGH);
}

void leftWheelsGoBackward() {
    digitalWrite(LEFT_REAR, LOW);
    digitalWrite(LEFT_FRONT, HIGH);
}

void rightWheelsGoBackward() {
    digitalWrite(RIGHT_REAR, HIGH);
    digitalWrite(RIGHT_FRONT, LOW);
}

void leftWheelsStop() {
    digitalWrite(LEFT_REAR, LOW);
    digitalWrite(LEFT_FRONT, LOW);
}

void rightWheelsStop() {
    digitalWrite(RIGHT_REAR, LOW);
    digitalWrite(RIGHT_FRONT, LOW);
}

void goForward() {
    setSpeed(carSpeed);
    rightWheelsGoForward();
    leftWheelsGoForward();
    Serial.println("Forward");
}

void goBackward() {
    setSpeed(carSpeed);
    rightWheelsGoBackward();
    leftWheelsGoBackward();
    Serial.println("Backward");
}

void goLeft() {
    setSpeed(carSpeed);
    leftWheelsGoBackward();
    rightWheelsGoForward();
    Serial.println("Left");
}

void goRight() {
    setSpeed(carSpeed);
    leftWheelsGoForward();
    rightWheelsGoBackward();
    Serial.println("Right");
}

// Speed 
void stop() {
    rightWheelsStop();
    leftWheelsStop();
    disableWheelsMotors();
    Serial.println("Stop");
}

void goFaster() {
    for (int i = 0; i <= 255; i++) {
      setSpeed(i);
      delay(20);
    }

    Serial.println("Faster");
}

void goSlower() {
    for (int i = 255; i >= 0; i--) {
      setSpeed(i);
      delay(20);
    }

    Serial.println("Slower");
}
