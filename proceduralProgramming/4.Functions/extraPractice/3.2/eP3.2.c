#include <stdio.h>
double getDecimalPart(double number);

int main(void)
{
  double inpNum;
  printf("please input a number: ");
  scanf("%lf", &inpNum);
  printf("the decimal part of this number is: %lf\n", getDecimalPart(inpNum));

  return 0;
}


double getDecimalPart(double number)
{
  double i = number;
  while(i > 1)
    i = i - 1;

  return i;

}
