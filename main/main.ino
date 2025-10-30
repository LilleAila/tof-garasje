/*
  * https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  * https://docs.arduino.cc/learn/electronics/servo-motors/
  * */
#include <Servo.h>

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
  unsigned long now = millis();

  handleDoor();
  handleAlarm();
  handleLeds();
  handleMovement();
}
