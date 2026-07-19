//===================================
// TB6612FNG Motor Test
// Arduino Nano
//===================================

/*Expected behavior
Robot moves straight forward.
Robot stops.
Robot pivots left (0,150).
Robot pivots right (150,0).
Robot spins left (-150,150).
Robot spins right (150,-150).*/

// Left Motor
#define AIN1 4
#define AIN2 5
#define PWMA 9

// Right Motor
#define BIN1 6
#define BIN2 7
#define PWMB 10

// Standby
#define STBY 8

//===================================

void setup()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(STBY, OUTPUT);

  // Enable TB6612
  digitalWrite(STBY, HIGH);
}

//===================================

void setMotor(int left, int right)
{
  left = constrain(left, -255, 255);
  right = constrain(right, -255, 255);

  // Left motor
  if(left >= 0)
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, left);
  }
  else
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, -left);
  }

  // Right motor
  if(right >= 0)
  {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, right);
  }
  else
  {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, -right);
  }
}

//===================================

void loop()
{
  // Forward
  setMotor(150,150);
  delay(3000);

  // Stop
  setMotor(0,0);
  delay(1000);

  // Left pivot
  setMotor(0,150);
  delay(3000);

  // Stop
  setMotor(0,0);
  delay(1000);

  // Right pivot
  setMotor(150,0);
  delay(3000);

  // Stop
  setMotor(0,0);
  delay(1000);

  // Spin left
  setMotor(-150,150);
  delay(3000);

  // Stop
  setMotor(0,0);
  delay(1000);

  // Spin right
  setMotor(150,-150);
  delay(3000);

  // Stop
  setMotor(0,0);
  delay(2000);
}