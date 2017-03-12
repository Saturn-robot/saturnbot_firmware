/* *************************************************************
   Encoder driver function definitions - by Chaoyang Liu
   ************************************************************ */

#ifndef ENCODER_DRIVER_H
#define ENCODER_DRIVER_H

#define LEFT_ENC_A 2
#define LEFT_ENC_B 22
#define RIGHT_ENC_A 21
#define RIGHT_ENC_B 24

void initEncoders();
void leftEncoderEvent();
void rightEncoderEvent();

long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();


#endif
