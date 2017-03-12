/***********************************************************************
   Motor driver - by Chaoyang Liu
   ***********************************************************************/
// motor one
#define ENA 5
#define IN1 7
#define IN2 8
// motor two
#define ENB 6
#define IN3 9
#define IN4 10

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
