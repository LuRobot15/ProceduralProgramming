#include <stdio.h>
#include <math.h>
int main()
{
  int x1, x2, y1, y2;
  printf("please enter the first X and Y coordinates with whitespace inbetween: ");
  scanf("%i%i", &x1, &y1);
  printf("please enter the second X and Y coordinates with whitespace inbetween: ");
  scanf("%i%i", &x2, &y2);
  double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  printf("the distance between the two points is %lf", distance);
  return 0;
}
