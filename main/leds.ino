// Led time used for debounce
unsigned long lastOutLed;

// Photoresistor value
int light = 0;

// This runs on every iteration. Sets the stats of both indoor and outdoor LEDs based on the photoresistor and the movement sensor for outdoor and indoor lights respectively.
void handleLeds() {
  if (now < lastMove + 5000 && !isLocked) {
    digitalWrite(inLedPin, HIGH);
  }
  else {
    digitalWrite(inLedPin, LOW);
  }

  light = analogRead(photoPin);

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
