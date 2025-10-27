#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trig, int echo) : trigPin(trig), echoPin(echo) {}

void Ultrasonic::begin() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float Ultrasonic::getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  return (duration * 0.0343) / 2.0;
}
