/*********************************************************************
   Motor driver function definitions 1- by James Nugen,Chaoyang Liu
   *******************************************************************/


void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int fleftSpeed, int frightSpeed, int bleftSpeed, int brightSpeed);

#ifdef L293D_MOTOR_DRIVE
  #include <AFMotor.h>
  //setting each motor
  AF_DCMotor rightFront(1);
  AF_DCMotor leftFront(2);
  AF_DCMotor leftBack(3);
  AF_DCMotor rightBack(4);

#endif // L293D_MOTOR_DRIVE
