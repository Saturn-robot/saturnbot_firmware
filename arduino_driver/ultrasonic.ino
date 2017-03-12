/***********************************************************************
   ultrasonic driver definitions - by Chaoyang Liu
   ***********************************************************************/
void initUltrasonic() {
  pinMode(EchoPin,INPUT);
  pinMode(TrigPin,OUTPUT);
}

float microsecondsToCm(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per cm.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

long get_distance() {
  long duration, range;

  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(50);
  digitalWrite(TrigPin,LOW);
  duration = pulseIn(EchoPin,HIGH);

  // convert the time into meters
  range = microsecondsToCm(duration);

  return(range);
}
