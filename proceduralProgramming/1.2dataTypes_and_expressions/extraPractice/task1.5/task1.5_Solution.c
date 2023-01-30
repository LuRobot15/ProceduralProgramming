#include <stdio.h>
#include <math.h>
int main()
{
  unsigned int acceleration, acTime, finalVelocity;
  double acDistance;
  printf("please input the rate of acceleration in M per second squared: ");
  scanf("%u", &acceleration);
  printf("please input the total time you accelerate for in seconds: ");
  scanf("%u", &acTime);
  finalVelocity = acceleration * acTime;
  acDistance = 0.5 * acceleration * pow(acTime, 2);
  unsigned int conTime;
  double conDistance, totDistance;
  printf("please input the amount of time the final velocity is maintained: ");
  scanf("%u", &conTime);
  conDistance = finalVelocity * conTime;
  totDistance = conDistance + acDistance;
  printf("the total distance traveled in %u seconds is %lf meters.", conTime + acTime, totDistance);
  return 0;
}
