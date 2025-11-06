// Button
int buttonState = LOW;
int lastButtonState = LOW;

// Piezo
bool alarmOn = false;
bool isLocked = false;
unsigned long alarmTime;
bool tonePlaying = false;

// This function runs on every iteration.
void handleAlarm() {
  // Play an annoying sounding interval repeatedly if the alarm is triggered.
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

  // Read the state of the button and toggle the alarm.
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    noTone(piezoPin);
    isLocked = !isLocked;
    alarmTime = now;
    tonePlaying = true;
  }
  lastButtonState = buttonState;

  // Play a short tone whenever the alarm is toggled to indicate whether or not it was turned on or off, and show that something happened.
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
