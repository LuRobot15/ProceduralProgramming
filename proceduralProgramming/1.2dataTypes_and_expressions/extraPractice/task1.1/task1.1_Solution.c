#include <stdio.h>
#include <math.h>
int main()
{
  double pi = 3.141592654;
  double d;
  printf("Please enter the diameter of the circle in M.cm: ");
  scanf("%lf", &d);
  double area = pi * pow(d/2, 2);
  printf("the area of the circle is %lf meters squared", area);
  return 0;
}
