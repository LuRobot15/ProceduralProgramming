#include <stdio.h>
#include <math.h>
int main()
{
  int cTemp;
  printf("please enter the tempurature in degres celcius: ");
  scanf("%i", &cTemp);
  double i = 9;
  double fTemp = (double) cTemp * (i/5) + 32;
  printf("the tempurature is %lf degrees fahrenheit", fTemp);
  return 0;
}
