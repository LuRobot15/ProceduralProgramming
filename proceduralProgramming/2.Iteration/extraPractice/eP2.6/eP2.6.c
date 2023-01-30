#include <stdio.h>
#include <math.h>

int main(void)
{
  double x;                                     //Collects a real input from the user
  printf("Please enter the real number: ");
  scanf("%lf", &x);

  int n;                                        //Collects an integer input from the user
  printf("Please enter the integer number: ");
  scanf("%i", &n);

  /*
  following loop finds all the powers of x required up to and including x^n and
  performs the relevant calculation (+ for even powers, - for odd powers) and stores the
  total under a variabl powersTotal.
  */
  double powersTotal = 0;
  for(int i = 1; i <= n; i++)
  {
    if(i % 2 == 0)    //condition to find if each x^n is added or subtracted from previous
    {
      powersTotal = powersTotal + pow(x, i);
    }
    else
    {
      powersTotal = powersTotal - pow(x, i);
    }
  }

  double answer;
  answer = 1 + powersTotal;    //finds the sum of 1 and the powers total and outputs it.
  printf("%lf", answer);

  return 0;
}
