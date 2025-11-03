int movementState = LOW;

void handleMovement() {
  movementState = digitalRead(movementSensor);
  if (movementState) {
    lastMove = now;
  }
  alarmOn = now < lastMove + 2000;
}
