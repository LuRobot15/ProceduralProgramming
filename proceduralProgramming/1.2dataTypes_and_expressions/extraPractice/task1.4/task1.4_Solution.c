#include <stdio.h>
#include <math.h>
int main()
{
  double f, g, m1,m2, r;
  g = 6.674 * pow(10, -11);
  printf("please enter the first mass: ");
  scanf("%lf", &m1);
  printf("please enter the second mass: ");
  scanf("%lf", &m2);
  printf("please enter the distance between the masses: ");
  scanf("%lf", &r);
  f = g * ((m1 * m2)/pow(r, 2));
  printf("the gravitational force between the objects is %e N\n", f);
  return 0;
}
