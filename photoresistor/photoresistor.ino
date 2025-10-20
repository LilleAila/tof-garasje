/*
* https://www.circuitbasics.com/how-to-use-photoresistors-to-detect-light-on-an-arduino/
* */

const int photo = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(photo);
  Serial.println(light);
}
