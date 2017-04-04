/***********************************************************************
   ultrasonic driver declarations - by Chaoyang Liu
 ***********************************************************************/

#define TrigPin 25
#define EchoPin 26

void initUltrasonic();
float microsecondsToCm(long microseconds);
long ultrasonic();
