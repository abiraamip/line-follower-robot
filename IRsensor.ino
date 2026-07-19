// 8-Channel Digital IR Sensor Test

int IRPins[8] = {A0, A1, A2, A3, A4, A5, 11, 12};

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 8; i++) {
    pinMode(IRPins[i], INPUT);
  }

  Serial.println("IR Sensor Test");
}

void loop() {

  for (int i = 0; i < 8; i++) {
    Serial.print(digitalRead(IRPins[i]));
    Serial.print(" ");
  }

  Serial.println();

  delay(100);
} 
