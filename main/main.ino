/*
  * https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  * https://docs.arduino.cc/learn/electronics/servo-motors/
  * */
#include "Door.h"
#include "Ultrasonic.h"

const int servoPin = 11;
const int trigPin = 9;
const int echoPin = 10;

Door door(servoPin);
Ultrasonic sensor(trigPin, echoPin);

void setup() {
  door.begin();
  sensor.begin();
}

void loop() {
  float distance = sensor.getDistance();
  unsigned long now = millis();

  door.update(distance, now);
  delay(100);
}
