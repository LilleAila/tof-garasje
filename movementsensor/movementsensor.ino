/*
  * https://projecthub.arduino.cc/electronicsfan123/interfacing-arduino-uno-with-pir-motion-sensor-593b6b
  * */

const int movementSensor = 8;
const int led = 9;

int movementState = LOW;

int lastMove;

void setup() {
  pinMode(movementSensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  movementState = digitalRead(movementSensor);
  Serial.println(movementState);

  if (movementState) {
    lastMove = millis();
  }

  digitalWrite(led, millis() < lastMove + 2000);
}
