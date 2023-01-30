#include <stdio.h>
double seriesReturn(double x, int n);

int main(void)
{
  int maxPower;
  double x;

  printf("please enter the x value: ");
  scanf("%lf", &x);

  printf("pleasee enter the highest power: ");
  scanf("%i", & maxPower);

  printf("the result of the series is: %lf\n", seriesReturn(x, maxPower));

  return 0;
}


double seriesReturn(double x, int n)
{
  if (n % 2 == 0)
  {
    double returnValue = 1;
    for (int i = 2; i <= n; i = i + 2)
    {
      int nextPower = 1;
      for (int j = 0; j < i; j++)
      {
        nextPower = nextPower * x;
      }
      returnValue = returnValue + nextPower;
    }
    return returnValue;
  }
  else
  {
    double returnValue = x;
    for (int i = 3; i <= n; i = i + 2)
    {
      int nextPower = 1;
      for (int j = 0; j < i; j++)
      {
        nextPower = nextPower * x;
      }
      returnValue = returnValue + nextPower;
    }
    return returnValue;
  }
}
