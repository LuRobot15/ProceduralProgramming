#include <stdio.h>
int getLargest(int a, int b, int c);

int main(void)
{
  int number1;
  int number2;
  int number3;

  printf("please enter 3 different integers: ");
  scanf("%i%i%i", &number1, &number2, &number3);

  printf("the largest of the integers entered was %i\n", getLargest(number1, number2, number3));

  return 0;
}


int getLargest(int a, int b, int c)
{
  if (a > b && a > c)
    return a;
  else
  {
    if (b > c && b > a)
      return b;
    else
      return c;
  }
}
