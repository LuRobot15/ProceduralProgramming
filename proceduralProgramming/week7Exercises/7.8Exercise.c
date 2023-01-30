#include <stdio.h>
#include <string.h>

int main(void)
{
  char inputString[20];
  char outputString[20];
  int offSet;

  printf("Please enter the string you want ciphered:\t");
  scanf("%[^\n]s", &inputString);
  printf("Please enter the key:\t");
  scanf("%i", &offSet);
  int stringLength = 0;

  while (stringLength < strlen(inputString))
  {
    if ((inputString[stringLength] >= 65) && (inputString[stringLength] <= 90))
    {
      if (inputString[stringLength] + offSet > 90)
      {
        outputString[stringLength] = inputString[stringLength] + offSet + 6;
      }
      else
      {
        outputString[stringLength] = inputString[stringLength] + offSet;
      }
    }
    else
    {
      if ((inputString[stringLength] >= 97) && (inputString[stringLength] <= 122))
      {
        if(inputString[stringLength] + offSet > 122)
        {
          outputString[stringLength] = inputString[stringLength] + offSet - 58;
        }
        else
        {
          outputString[stringLength] = inputString[stringLength] + offSet;
        }
      }
      else
        outputString[stringLength] = inputString[stringLength];
    }
    stringLength++;
  }
  outputString[stringLength] = '\0';
  printf("%s\n", outputString);
  return 0;
}
