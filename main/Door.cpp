#include "Door.h"

Door::Door(int pin) : servoPin(pin), isOpen(false), openedAt(0) {}

void Door::begin() {
  servo.attach(servoPin);
  close();
}

void Door::open() {
  servo.write(90);
  isOpen = true;
  openedAt = millis();
}

void Door::close() {
  servo.write(0);
  isOpen = false;
}

void Door::update(float distance, unsigned long now) {
  if (distance < 50) {
    if (!isOpen) open();
  }

  if (isOpen && now - openedAt >= openDuration) {
    close();
  }
}
