#ifndef DOOR_H
#define DOOR_H

#include <Arduino.h>
#include <Servo.h>

class Door {
  public:
    Door(int pin);
    void begin();
    void update(float distance, unsigned long now);

  private:
    Servo servo;
    int servoPin;
    bool isOpen;
    unsigned long openedAt;
    const unsigned long openDuration = 3000;
    void open();
    void close();
};

#endif
