#include <stdio.h>
#include <string.h>
int compareStrings(char string1[20], char string2[20]);


int main(void)
{
  char string1[20];
  char string2[20];
  printf("Please enter the first string: ");
  scanf("%s", &string1);
  printf("Please enter the scond string: ");
  scanf("%s", &string2);
  if (compareStrings(string1, string2) == 1)
    printf("The words entered are the same\n");
  else
    printf("You have entered 2 different words\n");

  return 0;
}

// compares 2 strings and returns true if they are the same and false otherwise
int compareStrings(char string1[20], char string2[20])
{
  if (strlen(string1) == strlen(string2))
  {
    for(int i = 0; i < strlen(string1); i++)
    {
      if (string1[i] != string2[i])
        return 0;
      else
        continue;
    }
  }
  else
    return 0;

  return 1;
}
