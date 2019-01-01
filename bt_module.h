bool ledState = LOW;
char btStr;
unsigned char carSpeed = 150;

void getBtStr() {
    btStr = Serial.read();
}

void toggleBtLed() {
    ledState = !ledState;
    digitalWrite(BT_LED, ledState);
}

void btActions() {
    getBtStr();

    switch(btStr) {
        case 'a':
            toggleBtLed();
            break;
        case 'f':
            goForward();
            break;
        case 'b':
            goBackward();
            break;
        case 'l':
            goLeft();
            break;
        case 'r':
            goRight();
            break;
        case 's':
            stop();
            break;
        default:
            break;
    }
}
