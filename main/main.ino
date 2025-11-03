/*
  * https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  * https://docs.arduino.cc/learn/electronics/servo-motors/
  * */
#include <Servo.h>

// Door
Servo servo;
const int servoPin = 11;

// Ultrasonic
const int trigPin = 9;
const int echoPin = 10;

// Alarm
const int outLedPin = 13;
const int inLedPin = 12;

// Leds
const int piezoPin = 6;
const int buttonPin = 4;

// Movementsensor
const int movementSensor = 8;
unsigned long lastMove;

unsigned long now;

void setup() {
  Serial.begin(9600);

  // Door
  servo.attach(servoPin);
  closeDoor();

  // Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Alarm
  pinMode(piezoPin, OUTPUT);
  pinMode(movementSensor, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // Leds
  pinMode(outLedPin, OUTPUT);
  pinMode(inLedPin, OUTPUT);
}

void loop() {
  delay(100);
  now = millis();

  handleDoor();
  handleAlarm();
  handleLeds();
  handleMovement();
}
