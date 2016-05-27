# include <SmartInventor.h>
void setup() {
  // put your setup code here, to run once:
  SmartInventor.Buzz(NOTE_C5, 16);
  delay(5000);
  pinMode(11, INPUT);
  pinMode(18, INPUT);

  SmartInventor.DCMotorUse();
}

void loop() {
  // put your main code here, to run repeatedly:
  int leftSensor = digitalRead(11);
  int rightSensor = digitalRead(18);

  if (leftSensor == LOW)
  {
     //backup
     SmartInventor.DCMotor(M1, CW, 50);
     SmartInventor.DCMotor(M2, CCW, 50);
     delay(644);


     //turn right
     SmartInventor.DCMotor(M1, CW, 80);
     SmartInventor.DCMotor(M2, CW, 80);
     delay(550);
  }
  // if right sees line, backup and turn left
  // otherwise go forward
  else if (rightSensor == LOW)
  {
    //backup
    SmartInventor.DCMotor(M1, CW, 50);
    SmartInventor.DCMotor(M2, CCW, 50);
    delay(644);

    //turn left
    SmartInventor.DCMotor(M1, CCW, 80);
    SmartInventor.DCMotor(M2, CCW, 80);
    delay(550);

  }
  // otherwise go forward
  else
  {
    // forward
    SmartInventor.DCMotor(M1, CCW, 80);
    SmartInventor.DCMotor(M2, CW, 80);
  }
}
