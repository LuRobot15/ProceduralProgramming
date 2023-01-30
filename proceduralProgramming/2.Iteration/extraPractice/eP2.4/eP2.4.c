#include <stdio.h>

int main(void)
{
  for(int power = 0; power <= 10; power++)
  {
    int number = 1;
    for(int i = 0; i < power; i++)
    {
      number = number *  2;
    }
    printf("2^%i = %i\n", power, number);
  }
  return 0;
}
