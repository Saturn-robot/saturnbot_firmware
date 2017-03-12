/***********************************************************************
   ultrasonic driver declarations - by Chaoyang Liu
 ***********************************************************************/

#define TrigPin 3
#define EchoPin 2

void initUltrasonic();
float microsecondsToCm(long microseconds);
long ultrasonic();
