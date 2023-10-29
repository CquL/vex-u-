#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#define MAX_SPEED 100 //速度上限；

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

  






  void SPEED_left(float *x,float *y,float *axisP_3,float* axisP_4)
  {
  // 纯前后移动
  if(*axisP_4 == 0) {
  *x = *axisP_3;
  *y = *axisP_3;

  //转向
  } else {  
  *x = (*axisP_3 + *axisP_4 );
  *y = (*axisP_3 - *axisP_4);
  }
  }
  
