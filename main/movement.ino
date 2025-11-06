// Whether or not the sensor detected movement
int movementState = LOW;

// Check if there was movement detected for every iteration.
void handleMovement() {
  movementState = digitalRead(movementSensor);
  if (movementState) {
    lastMove = now;
  }
  alarmOn = now < lastMove + 2000;
}
