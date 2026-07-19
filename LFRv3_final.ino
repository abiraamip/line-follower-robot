//===================================================
// 8 Channel Pattern Based Line Follower
// Arduino Nano + TB6612FNG
// Sensor: 1 = Black, 0 = White
//===================================================

//-------------- TB6612 ----------------
#define AIN1 4
#define AIN2 5
#define PWMA 9

#define BIN1 6
#define BIN2 7
#define PWMB 10

#define STBY 8

//-------------- Sensors ----------------
int sensorPins[8] = {A0, A1, A2, A3, A4, A5, 11, 12}; //12 and 12 takes PWM signals
int s[8];

int lastDirection = 0;

//===================================================

void setup()
{
  Serial.begin(9600);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);

  for(int i = 0; i < 8; i++)
    pinMode(sensorPins[i], INPUT);
}

//===================================================

void setMotor(int left, int right)
{
  left = constrain(left, -255, 255);
  right = constrain(right, -255, 255);

  // Left Motor
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

  // Right Motor
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

//===================================================

void readSensors()
{
  for(int i = 0; i < 8; i++)
    s[i] = digitalRead(sensorPins[i]);
}

//===================================================

void loop()
{
  readSensors();

  //----------- Debugging -----------
  /*
  for(int i=0;i<8;i++)
    Serial.print(s[i]);
  Serial.println();
  */

  //--------------- JUNCTION ----------------
  if(s[0]&&s[1]&&s[2]&&s[3]&&
     s[4]&&s[5]&&s[6]&&s[7])
  {
    setMotor(90,90);
    lastDirection = 0;
  }

  //--------------- CENTER ----------------
  else if(
          (s[2]&&s[3]&&s[4]&&s[5]) ||   //00111100
          (s[3]&&s[4]) ||
          (s[2]&&s[3]) ||
          (s[4]&&s[5])
         )
  {
    setMotor(100,100);
    lastDirection = 0;
  }

  //--------------- SHARP LEFT ----------------
  else if(
          (s[0]&&s[1]&&s[2]&&s[3]) ||   //11110000
          (s[0]&&s[1]&&s[2]&&s[3]&&s[4]) ||
          (s[0]&&s[1]&&s[2]&&s[3]&&s[4]&&s[5])
         )
  {
    setMotor(-100,150);
    lastDirection = -2;
  }

  //--------------- SLIGHT LEFT ----------------
  else if(
          (s[0]&&s[1]) ||               //11000000
          (s[0]&&s[1]&&s[2]) ||
          s[2]
         )
  {
    setMotor(50,130);
    lastDirection = -1;
  }

  //--------------- SHARP RIGHT ----------------
  else if(
          (s[5]&&s[6]&&s[7]) ||         //00000111
          (s[4]&&s[5]&&s[6]&&s[7]) ||
          (s[3]&&s[4]&&s[5]&&s[6]&&s[7])
         )
  {
    setMotor(150,-100);
    lastDirection = 2;
  }

  //--------------- SLIGHT RIGHT ----------------
  else if(
          (s[4]&&s[5]&&s[7]) ||         //00001101
          (s[6]&&s[7]) ||
          s[5]
         )
  {
    setMotor(130,50);
    lastDirection = 1;
  }

  //--------------- LOST LINE ----------------
  else
  {
    if(lastDirection < 0)
      setMotor(-80,80);      // search left

    else if(lastDirection > 0)
      setMotor(80,-80);      // search right

    else
      setMotor(0,0);
  }
}