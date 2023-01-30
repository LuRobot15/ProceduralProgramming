#include <stdio.h>
#include <math.h>

int main(void)
{
  printf("x          y\n");
  for(double x = 0; x < 3.2; x = x + 0.2)
  {
    double y = pow(x, 2) + 1.0;
    printf("%lf   %lf\n", x, y);
  }
  return 0;
}
