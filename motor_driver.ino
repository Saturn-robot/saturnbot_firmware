/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   
#ifdef POLOLU_VNH5019
  /* Include the Pololu library */
  #include "DualVNH5019MotorShield.h"

  /* Create the motor driver object */
  DualVNH5019MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined POLOLU_MC33926
  /* Include the Pololu library */
  #include "DualMC33926MotorShield.h"

  /* Create the motor driver object */
  DualMC33926MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined(L293D_MOTOR_DRIVE)
void initMotorController() {
  //do nothing
}

void setMotorSpeed(int i, int spd) {
  if (i == FLEFT) {
    if (spd > 0) {
      leftFront.setSpeed(spd);
      leftFront.run(FORWARD);
    }
    else {
      leftFront.setSpeed(-spd);
      leftFront.run(BACKWARD);
    }
  }
  else if (i == FRIGHT) {
    if (spd > 0) {
      rightFront.setSpeed(spd);
      rightFront.run(FORWARD);
    }
    else {
      rightFront.setSpeed(-spd);
      rightFront.run(BACKWARD);
    }
  }
  else if (i == BLEFT) {
    if (spd > 0) {
      leftBack.setSpeed(spd);
      leftBack.run(FORWARD);
    }
    else {
      leftBack.setSpeed(-spd);
      leftBack.run(BACKWARD);
    }
  }
  else {
    if (spd > 0) {
      rightBack.setSpeed(spd);
      rightBack.run(FORWARD);
    }
    else {
      rightBack.setSpeed(-spd);
      rightBack.run(BACKWARD);
    }
  }
}

void setMotorSpeeds(int fleftSpeed, int frightSpeed, int bleftSpeed, int brightSpeed) {
  setMotorSpeed(FLEFT, fleftSpeed);
  setMotorSpeed(FRIGHT, frightSpeed);
  setMotorSpeed(BLEFT, bleftSpeed);
  setMotorSpeed(BRIGHT, brightSpeed);
}
#else
  #error A motor driver must be selected!
#endif

#endif
