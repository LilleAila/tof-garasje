/*
  * https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  * https://docs.arduino.cc/learn/electronics/servo-motors/
  * */
#include <Servo.h>

// Door
Servo servo;
const int servoPin = 11;
bool doorOpen;
unsigned long doorOpenedAt = 0;
const unsigned long openDuration = 3000;

void openDoor() {
  servo.write(75);
  doorOpen = true;
}

void closeDoor() {
   servo.write(5);
   doorOpen = false;
}

// Ultrasonic distance sensor
const int trigPin = 9;
const int echoPin = 10;
float duration, distance;

float sensorGetDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2; // Speed of sound in micrometers per second
  return distance;
}

// Piezo
const int piezoPin = 6;
bool alarmOn = false;
bool isLocked = false;
unsigned long alarmTime;
bool tonePlaying = false;

// Movementsensor
const int movementSensor = 8;
int movementState = LOW;
unsigned long lastMove;

// Button
const int buttonPin = 4;
int buttonState = LOW;
int lastButtonState = LOW;

// Leds
const int outLedPin = 13;
const int inLedPin = 12;
unsigned long lastOutLed;

// Photoresistor
const int photo = A0;
int light = 0;

void setup() {
  Serial.begin(9600);

  servo.attach(servoPin);
  closeDoor();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Alarm
  pinMode(piezoPin, OUTPUT);
  pinMode(movementSensor, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(outLedPin, OUTPUT);
  pinMode(inLedPin, OUTPUT);
}

void loop() {
  delay(100);
  unsigned long now = millis();

  // Door
  distance = sensorGetDistance();
  if (distance < 50) {
    if (!doorOpen) {
      openDoor();
      doorOpenedAt = now;
    }
  }
  if (doorOpen && now - doorOpenedAt >= openDuration) {
    closeDoor();
  }

  // Alarm
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

  movementState = digitalRead(movementSensor);
  if (movementState) {
    lastMove = now;
  }
  alarmOn = now < lastMove + 2000;
  if (now < lastMove + 5000 && !isLocked) {
    digitalWrite(inLedPin, HIGH);
  }
  else {
    digitalWrite(inLedPin, LOW);
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
