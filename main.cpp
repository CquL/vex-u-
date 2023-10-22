/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       LEGION                                                    */
/*    Created:      2023/10/22 20:03:24                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"


using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
     vex::motor motor1(17);
     vex::motor motor2(16);
    vex::motor motor3(18);
    vex::motor motor4(19);
    vex::controller Controller;
       int MAX_SPEED = 1;//速度上限；        

        while(1) {

    float axisP_3 = Controller.Axis3.position();
    float axisP_4 = Controller.Axis4.position();
    
  // 根据摇杆位置计算左右轮的速度
  float speed1 = axisP_3 + axisP_4; 
  float speed2 = axisP_3 - axisP_4; 
    // 纯前后移动
  if(axisP_4 == 0) {
  speed1 = axisP_3;
  speed2 = axisP_3;

  // 左转  
  } else if(axisP_4 < 0) {  
  speed1 = (axisP_3 + axisP_4 );
  speed2 = (axisP_3 - axisP_4);

  // 右转
  } else {
  speed1 = (axisP_3 + axisP_4); 
  speed2 = (axisP_3- axisP_4);
  }

    motor1.spin(vex::directionType::rev, speed1, rpm);
    motor2.spin(vex::directionType::rev, speed1, rpm);
    motor3.spin(fwd, speed2, rpm);
    motor4.spin(fwd, speed2, rpm);
    }
 
    return 0;
}
