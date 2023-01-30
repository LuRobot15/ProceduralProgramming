#include <stdio.h>
#include <string.h>

// checks that the next characters after a t are: h, i and s
int checkRestOfWord(char scentance[], int scentanceLength, int currentPosition)
{
  char checkWord[] = "this";
  for (int j = 1; j < strlen(checkWord); j++)
  {
    if (checkWord[j] != scentance[currentPosition + j])
    {
      return 0;
    }
    else
    {
      continue;
    }
  }
  return 1;
}


int main(void)
{
  printf("Please enter the scentance: ");
  char scentance[1000];
  int scentanceLength = 0;
  char currentChar;
  while (1)
  {
    scanf("%c", &currentChar);
    if (currentChar == '.')
    {
      break;
    }
    else
    {
      scentance[scentanceLength] = currentChar;
    }
    scentanceLength++;
  }
  int wordOccurances = 0;
  for (int i = 0; i <=scentanceLength; i++)
  {
    if (((scentance[i] == 't') || (scentance[i] == 'T')) && (checkRestOfWord(scentance, scentanceLength, i) == 1))
      wordOccurances++;
  }
  printf("The word 'this' occurs %i times in the scentance.\n", wordOccurances);
  return 0;
}
