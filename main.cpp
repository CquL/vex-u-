/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       LEGION                                                    */
/*    Created:      9/27/2023, 7:42:26 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
    vex::motor motor1(0);
    vex::motor motor2(9);
    while(1)
    {
     motor1.spinToPosition(10.8, vex:: rotationUnits::rev,90, vex:: velocityUnits::rpm, true);
    motor2.spinToPosition(-10.6, vex:: rotationUnits::rev,90, vex:: velocityUnits::rpm, true);
     motor1.resetPosition();
     motor2.resetPosition();
     wait(100,msec);

    }
    //motor1.spinToPosition(360, vex:: rotationUnits::rev,1000, vex:: velocityUnits::rpm, true);
//public bool vex::motor::spinToPosition(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion=true)

    return 0;
}
