// Uno R3 pins
#define LEFT_SPEED 5
#define RIGHT_SPEED 6
#define LEFT_REAR 7
#define LEFT_FRONT 8
#define RIGHT_REAR 9
#define RIGHT_FRONT 11

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

// Wheels motors 
void enableWheelsMotors() {
  digitalWrite(RIGHT_SPEED, HIGH);
  digitalWrite(LEFT_SPEED, HIGH);
}

void disableWheelsMotors() {
  digitalWrite(RIGHT_SPEED, LOW);
  digitalWrite(LEFT_SPEED, LOW);
}

void stop() {
  rightWheelsStop();
  leftWheelsStop();
  disableWheelsMotors();
  Serial.println("Stop");
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
