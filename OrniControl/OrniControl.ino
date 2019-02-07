//#include <Servo.h>

#include <ESC.h>

#include "ESC.h"                                     // Pin for the LED 
#define SPEED_MIN (1000)                                  // Set the Minimum Speed in microseconds
#define SPEED_MAX (2000)

ESC myESC (10, SPEED_MIN, SPEED_MAX, 500);                 // ESC_Name (ESC PIN, Minimum Value, Maximum Value, Default Speed, Arm Value)
int oESC;

class ServoControl
{
  int chPin;
  int servoPin;
  int chVal;
  Servo servo;

  public:
  ServoControl(int cPin, int sPin)
  {
    chPin = cPin;
    servoPin = sPin;
  }
  void Setup()
  {
    pinMode(chPin, INPUT);
    servo.attach(servoPin);
  }
  void Move()
  {
    chVal=pulseIn(chPin, HIGH, 25000);
    if(chVal!=0)
    {
      chVal=map(chVal,1000,2000,0,180);
      servo.write(chVal);
    }
    
  }
};

ServoControl servo1(8,9);
ServoControl servo2(6,5);
//ServoControl servo3(4,3);

void setup()
{
  servo1.Setup();
  servo2.Setup();
  //servo3.Setup();
  myESC.arm();
  pinMode(7, INPUT);
  delay(1000); 
}

void loop()
{
  servo1.Move();
  servo2.Move();
  /*oESC=pulseIn(7, HIGH, 25000);
  if(oESC!=0){
    oESC=map(oESC, 1000, 2000, 1000, 2000);
    myESC.speed(oESC);
  }
  */
  //servo1.Move();
  //servo2.Move();
  /*oESC=pulseIn(7, HIGH, 25000);
  if(oESC!=0){
    oESC=map(oESC, 1000, 2000, 1000, 2000);
    myESC.speed(oESC);
  }
  */
}
