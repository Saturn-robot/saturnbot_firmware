  /*********************************************************************
   *  arduino driver for Saturn Robot:https://github.com/Saturn-robot/

     A set of simple serial commands to control a differential drive
     robot and receive back sensor and odometry data.I modify file
     "ROSArduinoBridge.ino" and get this file "arduino_driver.ino".
     Other files are all written by ourselves and inspired and modeled
     after by Patrick Goebel.

     Authors: Patrick Goebel, James Nugen
     Modified by Chaoyang Liu, email:chaoyanglius@gmail.com

     Inspired and modeled after the ArbotiX driver by Michael Ferguson

     Software License Agreement (BSD License)

     Copyright (c) 2012, Patrick Goebel.
     All rights reserved.

     Redistribution and use in source and binary forms, with or without
     modification, are permitted provided that the following conditions
     are met:

      * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.

     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
     "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
     LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
     FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
     COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
     INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
     BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
     CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
     LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
     ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  *  POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************/

/* Include the paramerers setting */
#include "params_setting.h"

#include "Arduino.h"
/* Include definition of serial commands */
#include "commands.h"

/* Sensor functions */
#include "ultrasonic.h"

/* Motor driver function definitions */
#include "motor_driver.h"

/* Encoder driver function definitions */
#include "encoder_driver.h"

/* PID parameters and functions */
#include "diff_controller.h"

/* IMU driver functions definitions */
#include <Wire.h>
#include <GY85.h>

/* Variable initialization */

// A pair of varibles to help parse serial commands (thanks Fergs)
int arg = 0;
int index = 0;

// Variable to hold an input character
char chr;

// Variable to hold the current single-character command
char cmd;

// Character arrays to hold the first and second arguments
char argv1[16];
char argv2[16];

// The arguments converted to integers
long arg1;
long arg2;

GY85 gy85(1234, 1235, 1236);
imuData imu_data;
/* Clear the current command parameters */
void resetCommand()
{
  cmd = NULL;
  memset(argv1, 0, sizeof(argv1));
  memset(argv2, 0, sizeof(argv2));
  arg1 = 0;
  arg2 = 0;
  arg = 0;
  index = 0;
}

/* Run a command.  Commands are defined in commands.h */
int runCommand()
{
  int i = 0;
  char *p = argv1;
  char *str;
  int pid_args[4];
  arg1 = atoi(argv1);
  arg2 = atoi(argv2);

  switch(cmd) {
  case GET_BAUDRATE:
    Serial.println(BAUDRATE);
    break;
  case ANALOG_READ:
    Serial.println(analogRead(arg1));
    break;
  case DIGITAL_READ:
    Serial.println(digitalRead(arg1));
    break;
  case ANALOG_WRITE:
    analogWrite(arg1, arg2);
    Serial.println("OK");
    break;
  case DIGITAL_WRITE:
    if (arg2 == 0) digitalWrite(arg1, LOW);
    else if (arg2 == 1) digitalWrite(arg1, HIGH);
    Serial.println("OK");
    break;
  case PIN_MODE:
    if (arg2 == 0) pinMode(arg1, INPUT);
    else if (arg2 == 1) pinMode(arg1, OUTPUT);
    Serial.println("OK");
    break;
  case ULTRASONIC:
    Serial.println(get_distance());
    break;
  case READ_ENCODERS:
    Serial.print(readEncoder(LEFT));
    Serial.print(" ");
    Serial.println(readEncoder(RIGHT));
    break;
   case RESET_ENCODERS:
    resetEncoders();
    resetPID();
    Serial.println("OK");
    break;
  case MOTOR_SPEEDS:
    /* Reset the auto stop timer */
    lastMotorCommand = millis();
    if (arg1 == 0 && arg2 == 0)
    {
      setMotorSpeeds(0, 0);
      resetPID();
      moving = 0;
    }
    else moving = 1;
    leftPID.TargetTicksPerFrame = arg1;
    rightPID.TargetTicksPerFrame = arg2;
    Serial.println("OK");
    break;
  case UPDATE_PID:
    while ((str = strtok_r(p, ":", &p)) != '\0')
    {
       pid_args[i] = atoi(str);
       i++;
    }
    Kp = pid_args[0];
    Kd = pid_args[1];
    Ki = pid_args[2];
    Ko = pid_args[3];
    Serial.println("OK");
    break;
  case READ_IMU:
    imu_data = gy85.readIMU();
    /* Send the IMU data base in the following order
     * [ax, ay, az, gx, gy, gz, mx, my, mz, roll, pitch, ch]
     */
    Serial.print(imu_data.ax);
    Serial.print(F(" "));
    Serial.print(imu_data.ay);
    Serial.print(F(" "));
    Serial.print(imu_data.az);
    Serial.print(F(" "));
    Serial.print(imu_data.gx);
    Serial.print(F(" "));
    Serial.print(imu_data.gy);
    Serial.print(F(" "));
    Serial.print(imu_data.gz);
    Serial.print(F(" "));
    Serial.print(imu_data.mx);
    Serial.print(F(" "));
    Serial.print(imu_data.my);
    Serial.print(F(" "));
    Serial.println(imu_data.mz);
    // Serial.print(F(" "));
    // Serial.print(imu_data.roll);
    // Serial.print(F(" "));
    // Serial.print(imu_data.pitch);
    // Serial.print(F(" "));
    // Serial.println(imu_data.ch);
    break;
  default:
    Serial.println("Invalid Command");
    break;
  }
}

/* Setup function--runs once at startup. */
void setup()
{
  Serial.begin(BAUDRATE);

// Initialize sensors
  initMotorController();
  initEncoders();
  gy85.init();
  initUltrasonic();
  resetPID();
}

/* Enter the main loop.  Read and parse input from the serial port
   and run any valid commands. Run a PID calculation at the target
   interval and check for auto-stop conditions.
*/
void loop()
{
  while (Serial.available() > 0)
  {

    // Read the next character
    chr = Serial.read();

    // Terminate a command with a CR
    if (chr == 13)
    {
      if (arg == 1) argv1[index] = NULL;
      else if (arg == 2) argv2[index] = NULL;
      runCommand();
      resetCommand();
    }
    // Use spaces to delimit parts of the command
    else if (chr == ' ')
    {
      // Step through the arguments
      if (arg == 0) arg = 1;
      else if (arg == 1)
      {
        argv1[index] = NULL;
        arg = 2;
        index = 0;
      }
      continue;
    }
    else
    {
      if (arg == 0)
      {
        // The first arg is the single-letter command
        cmd = chr;
      }
      else if (arg == 1)
      {
        // Subsequent arguments can be more than one character
        argv1[index] = chr;
        index++;
      }
      else if (arg == 2)
      {
        argv2[index] = chr;
        index++;
      }
    }
  }

// If we are using base control, run a PID calculation at the appropriate intervals
  if (millis() > nextPID)
  {
    updatePID();
    nextPID += PID_INTERVAL;
  }

  // Check to see if we have exceeded the auto-stop interval
  if ((millis() - lastMotorCommand) > AUTO_STOP_INTERVAL)
  {
    setMotorSpeeds(0, 0);
    moving = 0;
  }
}
