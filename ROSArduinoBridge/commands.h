/***********************************************************************
    This file is from James Nugen's pirobot which lives at:
    https://github.com/hbrobotics/ros_arduino_bridge ,
    and I modified it to adapt my own robot.
************************************************************************/

/* Define single-letter commands that will be sent by the PC over the
   serial link.
*/

#ifndef COMMANDS_H
#define COMMANDS_H

#define ANALOG_READ    'a'
#define GET_BAUDRATE   'b'
#define PIN_MODE       'c'
#define DIGITAL_READ   'd'
#define READ_ENCODERS  'e'
#define MOTOR_SPEEDS   'm'
#define PING           'p'
#define RESET_ENCODERS 'r'
#define SERVO_WRITE    's'
#define SERVO_READ     't'
#define UPDATE_PID     'u'
#define DIGITAL_WRITE  'w'
#define ANALOG_WRITE   'x'
#define FLEFT           1
#define FRIGHT          0
#define BLEFT           3
#define BRIGHT          2
/*These Mcro is used to debug*/
#define READ_MOTORS     'M'
/*--------------------------*/

#endif
