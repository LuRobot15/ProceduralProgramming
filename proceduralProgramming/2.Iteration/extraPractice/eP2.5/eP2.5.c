#include <stdio.h>

int main(void)
{
  printf("Please input an integer: ");

  int factorialNumber;
  scanf("%i", &factorialNumber);

  if(factorialNumber == 0)
  {
    printf("0! = 0");
  }
  else
  {
    int answer = 1;
    for(int i = 1; i <= factorialNumber; i++)
    {
      answer = answer * i;
    }
    printf("%i! = %i", factorialNumber, answer);
  }
  return 0;
}
