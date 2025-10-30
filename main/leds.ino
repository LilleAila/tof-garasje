// Leds
const int outLedPin = 13;
const int inLedPin = 12;
unsigned long lastOutLed;

// Photoresistor
const int photo = A0;
int light = 0;

void handleLeds() {
  if (now < lastMove + 5000 && !isLocked) {
    digitalWrite(inLedPin, HIGH);
  }
  else {
    digitalWrite(inLedPin, LOW);
  }

  light = analogRead(photo);

  if (light < 300) {
    lastOutLed = now;
  }

  if (now <= lastOutLed + 3000) {
    digitalWrite(outLedPin, HIGH);
  }
  else {
    digitalWrite(outLedPin, LOW);
  }
}
