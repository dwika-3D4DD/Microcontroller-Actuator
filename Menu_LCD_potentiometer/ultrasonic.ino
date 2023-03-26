void readUltra() {
  digitalWrite(SRF_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(SRF_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(SRF_trig, LOW);
  long duration = pulseIn(SRF_echo, HIGH, 8000);
  SRFVal = duration / 29.1 / 2;
}
