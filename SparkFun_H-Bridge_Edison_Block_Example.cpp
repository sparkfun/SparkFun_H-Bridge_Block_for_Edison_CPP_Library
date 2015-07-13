#include <unistd.h>

#include "mraa.h"
#include "SparkFun_TB6612_Edison.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

  // The constructor for the tb6612 class object configures all the necessary
  //  pins, exporting them if they aren't already exported, etc. Note that only
  //  one tb6612 class object may exist at a time, as they share hardware
  //  resources!
  tb6612 motors;

  // The constructor disables the outputs of the tb6612 by asserting the standby
  //  pin on the controller. You *must* use the standby() function to enable
  //  them before proceeding!
  motors.standby(false);

  // diffDrive() accepts a floating point number for channel A and channel B, in
  //  the range -1.0 to 1.0 inclusive.
  motors.diffDrive(0.5,0.5);
  sleep(5);
  motors.diffDrive(-0.5,-0.5);
  sleep(5);

  // "short brake" literally means the two outputs are shorted together. This
  //  drags the motor to a halt in a very short time and then holds it still
  //  (albeit fairly weakly). The shortBrake() function doesn't change the
  //  PWM output settings, so when shortBrake() is released by sending a "false"
  //  parameter, the motor will immediately resume its previous speed.
  motors.shortBrake(true, true);

  // Return the motors to hi-z state. This also doesn't affect the PWM output,
  //  so when standby is released (by passing false to this function) the motors
  //  will immediately resume their former speeds. This also doesn't provide any
  //  braking, so the motors will coast to a stop much more slowly than with
  //  shortBrake().
  motors.standby(true);

  bool brakeA = false;
  bool brakeB = false;
  float dcA = 0;
  float dcB = 0;
  bool onStandby = false;

  // We've provided a number of "get" functions, to check the current status of
  //  the device.

  // getStandby() returns true if the motors are on standby, false otherwise.
  //  This function checks the actual status of the gpio pin used for setting
  //  the standby mode on the chip, so it will always match reality.
  onStandby = motors.getStandby();

  // getDiffDrive() checks the *stored* speed value, rather than the current
  //  value. Thus, if another process alters the PWM output duty cycle without
  //  actually touching the class object, this may return invalid data. It also
  //  doesn't return any information about standby or brake status.
  motors.getDiffDrive(&dcA, &dcB);

  // getShortBrake() checks the pins used for setting the direction/brake mode,
  //  so the values placed into the pointer parameters by the function are
  //  accurate at the time the function is called.
  motors.getShortBrake(&brakeA, &brakeB);

  cout<<"Motor standby status: "<< boolalpha << onStandby << endl;
  cout<<"Motor A brake status: "<< brakeA << endl;
  cout<<"Motor B brake status: "<< brakeB << endl;
  cout<<"Channel A speed: "<< fixed << setprecision(3)<<dcA<<endl;
  cout<<"Channel B speed: "<<dcB<<endl;

  return 0;
}
