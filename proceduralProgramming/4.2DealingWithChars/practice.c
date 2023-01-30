#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Please input a character: ");
  char c;
  scanf(" %c", &c);

  if (c >= 65 && c <= 90)
  {
    printf("The character entered is upper case. \n The lower case version is %c \n", c + 32);
  }
  else
  {
    if (c >= 97 && c <= 122)
    {
      printf("The character entered is lower case. \n The upper case version is %c \n", c - 32);
    }
    else
    {
      printf("That was not a character you moron!\n");
      exit(0);
    }
  }

  return 0;
}
