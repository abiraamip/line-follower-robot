void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(A0));
  delay(100);
}
