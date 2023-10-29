/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       LEGION                                                    */
/*    Created:      2023/10/23 10:37:04                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"


using namespace vex;
// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
    vex::controller Controller;
    vex::motor motor1(17,true);
    vex::motor motor2(16,true);
    vex::motor motor3(18);
    vex::motor motor4(19);//底盘


    vex::motor motor5(0,true);
    vex::motor motor6(9);//吸/吐球

    vex::motor motor7(1,true);//弹射
    vex::motor motor8(8);

    vex::motor motor9(10,true);//拉杆
    vex::motor motor10(11);

// define your global instances of motors and other devices here

float speed1 ; //初始化变量速度
float speed2 ; 
int flag_A=0;//按件状态
int v_xi=0;//吸球速度
int v_tu=0;
int flag_L1 =0;
int v_tan = 0;
float v_gan=0;


  void run_XI(void)//吸球
  {
    v_xi = MAX_SPEED;
  }

  
  void   run_B_TU(void)//吐球
  {
    v_xi = (-2)*MAX_SPEED;
  }


  void STOP_A(void)//电机停转 吸吐球
  {
     flag_A=-1;
     v_xi = 0;
 }

  void STOP_L1(void)//电机停转 ，（弹射）
  {
     v_tan = 0;
  }
  
  void STOP_L2(void)//电机停转，吊车
  {
     
     v_gan = 0;
  }
  
  void run_L2_down(void)//吊车
  {
    v_gan = MAX_SPEED;
  }


  void run_L2_up(void)//吊车
  {
    v_gan = -MAX_SPEED;
  }




    int main(){
  while(1) {

     Controller.ButtonA.pressed(run_XI);//按键A pressed
    Controller.ButtonB.pressed(run_B_TU);//按键B pressed 吐球
     Controller.ButtonA.released(STOP_A);//停止吸球
     Controller.ButtonB.released(STOP_A);//停止吸球


      bool  L1Pressing = Controller.ButtonL1.pressing();//弹射
    if(L1Pressing)
        v_tan = MAX_SPEED;
   Controller.ButtonL1.released(STOP_L1);//停止

   Controller.ButtonL2.pressed(run_L2_down);//按键L2 pressed
   Controller.ButtonL2.released(STOP_L2);//停止

   Controller.ButtonR2.pressed(run_L2_up);//按键L2 pressed
   Controller.ButtonR2.released(STOP_L2);//停止






    float axisP_3 = Controller.Axis3.position();//提取摇杆参数
    float axisP_4 = Controller.Axis4.position();


   SPEED_left( &speed1, &speed2, &axisP_3, &axisP_4);//速度函数

    motor1.spin(fwd, speed1, rpm);
    motor2.spin(fwd, speed1, rpm);
    motor3.spin(fwd, speed2, rpm);
    motor4.spin(fwd, speed2, rpm);
    
    motor5.spin(fwd, v_xi, rpm);
    motor6.spin(fwd, v_xi, rpm);//吸吐球


    motor7.spin(fwd, v_tan ,rpm);//弹射
    motor8.spin(fwd, v_tan, rpm);//
  
    motor9.spin(fwd, v_gan ,rpm);//吊杆
    motor10.spin(fwd, v_gan, rpm);//


    

     }

    return 0;
}
