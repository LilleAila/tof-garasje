const int movementSensor = 8;
int movementState = LOW;
unsigned long lastMove;

void handleMovement() {
  movementState = digitalRead(movementSensor);
  if (movementState) {
    lastMove = now;
  }
  alarmOn = now < lastMove + 2000;
}
