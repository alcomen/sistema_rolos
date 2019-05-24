#include <Stepper.h>

#define motor 2
#define up    3
#define down  4
#define cw    9

char speed_stepper = 60;
const int stepsPerRevolution = 200;

Stepper stepper(stepsPerRevolution, 5,6,7,8);

void setup() {
  // put your setup code here, to run once:
  pinMode(motor, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(cw, INPUT);
  stepper.setSpeed(speed_stepper);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //stepper.step(-stepsPerRevolution);
  if(digitalRead(motor)) stepper.step(stepsPerRevolution);
  if(digitalRead(up))
  {
    if(speed_stepper > 150) speed_stepper = 150;else
    speed_stepper += 5;
  }

  if(digitalRead(down))
  {
    if(speed_stepper <1) speed_stepper = 0;else
    speed_stepper -= 5;
  }
  delay(10);
  stepper.setSpeed(speed_stepper);
}
