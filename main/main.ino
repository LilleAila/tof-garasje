/*
  * https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  * https://docs.arduino.cc/learn/electronics/servo-motors/
  * */
#include <Servo.h>

Servo myservo;
const int servoPin = 11;
int pos = 90;
bool doorOpen;
unsigned long doorOpenedAt = 0;
const unsigned long openDuration = 3000;

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;



void setup() {
  myservo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}


void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2; // Speed of sound in micrometers per second
	Serial.println(distance);


  unsigned long now = millis();
  if (distance < 50) {
    doorOpenedAt = now;

    if (!doorOpen) {
      myservo.write(90);
      doorOpen = true;
    }
  }

  if (doorOpen && millis() - doorOpenedAt >= openDuration) {
    myservo.write(0);
    doorOpen = false;
  }

  delay(100);
}
