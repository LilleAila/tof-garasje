/*
  * https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  * https://docs.arduino.cc/learn/electronics/servo-motors/
  * */
#include <Servo.h>

// Door
Servo servo;
const int servoPin = 11;
int pos = 90;
bool doorOpen;
unsigned long doorOpenedAt = 0;
const unsigned long openDuration = 3000;

void openDoor() {
  servo.write(90);
  doorOpen = true;
}

void closeDoor() {
   servo.write(0);
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

void setup() {
  servo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() {
  distance = sensorGetDistance();
  unsigned long now = millis();
  if (distance < 50) {
    if (!doorOpen) {
      openDoor();
      doorOpenedAt = now;
    }
  }
  if (doorOpen && millis() - doorOpenedAt >= openDuration) {
    closeDoor();
  }

  delay(100);
}
