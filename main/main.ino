/*
  * Sources:
  * Movement sensor: https://projecthub.arduino.cc/electronicsfan123/interfacing-arduino-uno-with-pir-motion-sensor-593b6b
  * Photoresistor: https://www.circuitbasics.com/how-to-use-photoresistors-to-detect-light-on-an-arduino/
  * Servo motor: https://docs.arduino.cc/learn/electronics/servo-motors/
  * Ultrasonic sensor: https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  * */
#include <Servo.h>

// Door
Servo servo;
const int servoPin = 11;

// Ultrasonic
const int trigPin = 9;
const int echoPin = 10;

// LEDs
const int outLedPin = 13;
const int inLedPin = 12;

// Photoresistor
const int photoPin = A0;

// Alarm
const int piezoPin = 6;
const int buttonPin = 4;

// Movement sensor
const int movementSensor = 8;
unsigned long lastMove;

unsigned long now;

void setup() {
  // Initialize all components and pins

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
  delay(100); // Loop does not need to run all of the time. This avoids unnecessary computations.
  now = millis();

  // Run functions for various components. These are defined in separate files.
  handleDoor();
  handleAlarm();
  handleLeds();
  handleMovement();
}
