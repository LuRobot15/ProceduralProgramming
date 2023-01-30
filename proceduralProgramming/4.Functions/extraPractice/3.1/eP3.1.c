#include <stdio.h>
int sum(int a, int b, int c);

int main(void)
{
  int number1;
  int number2;
  int number3;

  printf("please input 3 integers:");
  scanf("%i%i%i", &number1, &number2, &number3);
  printf("The sum of the three numbers is %i\n", sum(number1, number2, number3));

  return 0;
}


int sum(int a, int b, int c)
{
  return a + b + c;
}
