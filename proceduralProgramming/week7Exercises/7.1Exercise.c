#include <stdio.h>
#include <string.h>
#define maxStringLength 20

int main(void)
{
  char firstName[maxStringLength];
  char surname[maxStringLength];

  printf("Please enter your first and last name: ");
  scanf("%s%s", &firstName, &surname);

  if (firstName[0] > 90)
  {
    firstName[0] -= 32;
  }
  if (surname[0] > 90)
  {
    surname[0] -= 32;
  }
  printf("your second name is %s, and your first name is %s\n", surname, firstName);

  return 0;
}
