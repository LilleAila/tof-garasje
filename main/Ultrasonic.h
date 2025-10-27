#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {
  public:
    Ultrasonic(int trig, int echo);
    void begin();
    float getDistance();

  private:
    int trigPin;
    int echoPin;
};

#endif
