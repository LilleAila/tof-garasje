// https://docs.arduino.cc/learn/electronics/servo-motors/
#include <Servo.h>

Servo myservo;
int pos;


void setup() {
  myservo.attach(9);
}


void loop() {
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  // for (pos = 0; pos <= 180; pos++) {
  //   myservo.write(pos);
  //   delay(15);
  // }
  // for (pos = 180; pos >= 0; pos--) {
  //   myservo.write(pos);
  //   delay(15);
  // }
}
