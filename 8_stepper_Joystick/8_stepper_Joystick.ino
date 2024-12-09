/*
   Sketching mit Hardware
  DMP WS2425
  - Stepper (28BYJ-48 mit ULN2003A Driver)
  This project demonstrates how to move a stepper motor with a joystick
  
  Martinez
*/

#include <Stepper.h>

#define STEPS 32

// define stepper motor control pins
#define IN1 5
#define IN2 6
#define IN3 7
#define IN4 8

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
// initialize stepper library
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);

// joystick pot output is connected to Arduino A0
#define joystick A2

void setup()
{

}

void loop()
{
  // read analog value from the potentiometer
  int val = analogRead(joystick);

  // if the joystic is in the middle ===> stop the motor
  if ( (val > 500) && (val < 523) )
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  else
  {
    // move the motor in the first direction
    while (val >= 523)
    {
      // map the speed between 5 and 500 rpm
      int speed_ = map(val, 523, 1023, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);

      // move the motor (1 step)
      stepper.step(10);

      val = analogRead(joystick);
    }

    // move the motor in the other direction
    while (val <= 500)
    {
      // map the speed between 5 and 500 rpm
      int speed_ = map(val, 500, 0, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);

      // move the motor (1 step)
      stepper.step(-10);

      val = analogRead(joystick);
    }

  }

}
