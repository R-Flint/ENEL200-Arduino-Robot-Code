#include <UcTTDcMotor.h>
#include <math.h>
#define encoder 2

UcTTDcMotor motorL(D3, D9); //Initialization for the left side motor (veiwed from rear of robot)
UcTTDcMotor motorR(D10, D11); //Initialization for the right side motor (veiwed from rear of robot)


//Definitons for constant values needed for the program
uint8_t WHEEL_DIAMETER = 65;
uint8_t ENCODER_RESOLUTION = 20;
uint8_t TICK_DISTANCE = (WHEEL_DIAMETER * 3.14)/ENCODER_RESOLUTION; //Defines the equivalent radial distance between wheel encoder spokes
volatile byte tickCount;

void count(){
  tickCount++;
}

uint32_t tickConverter(uint8_t distance)
{
  return (distance/TICK_DISTANCE);
}

void forwardMove(uint32_t tickGoal)
{
  tickCount = 0;
  //Sets the motor speeds for each motor to movement speed
  motorL.forward(60);
  motorR.forward(60);
  //Does nothing while the number of ticks is less than the required tick number
  while (tickCount <= tickGoal) {
    printf("Tick count: %d\n", tickCount);
    count();
  }
  motor1.stop();
  motor2.stop();

}

void backwardMove(uint32_t tickGoal)
{
  tickCount = 0;
  //Sets the motor speeds for each motor to movement speed
  motorL.backward(60);
  motorR.backward(60);
  //Does nothing while the number of ticks is less than the required tick number
  while (tickCount <= tickGoal) {
    printf("Tick count: %d\n", tickCount);
    count();
  }
  motor1.stop();
  motor2.stop();

}

void leftMove(uint32_t tickGoal)
{
  tickCount = 0;
  //Sets the motor speeds for each motor to movement speed
  motorL.backward(60);
  motorR.forward(60);
  //Does nothing while the number of ticks is less than the required tick number
  while (tickCount <= tickGoal) {
    printf("Tick count: %d\n", tickCount);
    count();
  }
  motor1.stop();
  motor2.stop();

}

void rightMove(uint32_t tickGoal)

{
  tickCount = 0;
  //Sets the motor speeds for each motor to movement speed
  motorL.forward(60);
  motorR.backward(60);
  //Does nothing while the number of ticks is less than the required tick number
  while (tickCount <= tickGoal) {
    printf("Tick count: %d\n", tickCount);
    count();
  }
  motor1.stop();
  motor2.stop();

}



void setup() {
  //Motor setup
  tickCount = 0;
  motor1.init();

  //Sets up the wheel encoders to interupt the code with pulses
  Serial.begin(9600);
  pinMode(encoder, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoder), count, FALLING);

}



void loop() {
  if (Serial.available() > 0) 

  {
    int32_t command = Serial.parseInt();
    forwardMove(command);
  }

  

}
