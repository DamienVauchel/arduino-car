void enableWheelsMotors() {
  digitalWrite(RIGHT_SPEED, HIGH);
  digitalWrite(LEFT_SPEED, HIGH);
}

void disableWheelsMotors() {
  digitalWrite(RIGHT_SPEED, LOW);
  digitalWrite(LEFT_SPEED, LOW);
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
  enableWheelsMotors();
  rightWheelsGoForward();
  leftWheelsGoForward();
  Serial.println("Forward");
}

void goBackward() {
  enableWheelsMotors();
  rightWheelsGoBackward();
  leftWheelsGoBackward();
  Serial.println("Backward");
}

void goLeft() {
  enableWheelsMotors();
  leftWheelsGoBackward();
  rightWheelsGoForward();
  Serial.println("Left");
}

void goRight() {
  enableWheelsMotors();
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

void setSpeed(int nb) {
  analogWrite(RIGHT_SPEED, nb);
  analogWrite(LEFT_SPEED, nb);
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
