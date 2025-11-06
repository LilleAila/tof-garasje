// Ultrasonic distance sensor
float duration, distance;

// Read the distance from the pins of the sensor, and convert to a usable unit
float sensorGetDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2; // Speed of sound in micrometers per second
  return distance;
}

// Door
bool doorOpen;
unsigned long doorOpenedAt = 0;
const unsigned long openDuration = 3000;

// Set the door to specific angles for open and closed
void openDoor() {
  servo.write(75);
  doorOpen = true;
}

void closeDoor() {
   servo.write(5);
   doorOpen = false;
}

// This function runs on every iteration, and opens / closes the door based on the sensor and the defined debounce time.
void handleDoor() {
  distance = sensorGetDistance();
  if (distance < 50) {
    if (!doorOpen) {
      openDoor();
      doorOpenedAt = now;
    }
  }
  if (doorOpen && now - doorOpenedAt >= openDuration) {
    closeDoor();
  }
}
