// Button
int buttonState = LOW;
int lastButtonState = LOW;

// Piezo
bool alarmOn = false;
bool isLocked = false;
unsigned long alarmTime;
bool tonePlaying = false;

void handleAlarm() {
  if (alarmOn && isLocked && !tonePlaying) {
    if (now / 500 % 2 == 0) {
      tone(piezoPin, 440);
    }
    else {
      tone(piezoPin, 622); // tritone
    }
  }
  else {
    noTone(piezoPin);
    alarmOn = false;
  }

  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    noTone(piezoPin);
    isLocked = !isLocked;
    alarmTime = now;
    tonePlaying = true;
  }
  lastButtonState = buttonState;

  if (tonePlaying && isLocked) {
    if (now >= alarmTime + 500) {
      noTone(piezoPin);
      tonePlaying = false;
    }
    else if (now >= alarmTime + 300) {
      tone(piezoPin, 660);
    }
    else if (now >= alarmTime + 100) {
      tone(piezoPin, 990);
    }
  }
  if (tonePlaying && !isLocked) {
    if (now >= alarmTime + 500) {
      noTone(piezoPin);
      tonePlaying = false;
    }
    else if (now >= alarmTime + 300) {
      tone(piezoPin, 990);
    }
    else if (now >= alarmTime + 100) {
      tone(piezoPin, 660);
    }
  }
}
