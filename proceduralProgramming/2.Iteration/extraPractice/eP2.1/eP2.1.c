#include <stdio.h>

int main(void)
{
  printf("please enter an integer: ");

  int i;
  scanf("%i", &i);

  if(i % 2 == 0)
  {
    printf("The number is even\n");
  }
  else
  {
    printf("The number is odd\n");
  }
}
