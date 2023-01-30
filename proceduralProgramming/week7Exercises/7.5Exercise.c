#include <stdio.h>
#include <string.h>
#define string 20

double compareStrings(char string1[string], char string2[string]);


int main(void)
{
  char string1[string]; //declares the first variable that will store the user's first input
  char string2[string]; //declares the second variable that will store the user's second input

  printf("Please enter the first string:\t"); //prompts the user to enter their first input string
  scanf("%s", &string1);  //stores the users input in the variable string 1

  printf("Please enter the second string:\t");  //prompts the user to enter their second input string
  scanf("%s", &string2);  //stores the users input as a string in the variable string2

  printf("\"%s\" is %.0lf percent identical to \"%s\" \n", string1, compareStrings(string1, string2) * 100, string2);
}


double compareStrings(char string1[string], char string2[string])
{
  char useString1[string];  //creates a new variable that will be used instead of "string1"
  char useString2[string];  //creates a new variable that will be used instead of "string2"
  strcpy(useString1, string1);  //gives useString1 he value of string1 so that if it needs to be padded for the comparison, string1 is not effected
  strcpy(useString2, string2);  //gives useString2 he value of string2 so that if it needs to be padded for the comparison, string2 is not effected

  if (strlen(string1) < strlen(string2))
  {
    while(strlen(useString1) < strlen(useString2))
    {
      strcat(useString1, "$"); //padds string1 with "$" until it is the sam length as string2
    }
  }
  if (strlen(string2) < strlen(string1))
  {
    while(strlen(useString2) < strlen(useString1))
    {
      strcat(useString2, "$"); //padds string2 with "$" until it is the sam length as string1
    }
  }

  int equalChars = 0; //stores the number of indexes that are equal in each string
  for (int i = 0; i < strlen(useString1); i++) //traverses the length of both strings (as they now have equal length)
  {
    if (useString1[i] == useString2[i])
    {
      equalChars++; //increments the equalChars variable if two indexes store the same character
    }
  }

  return (double) equalChars / strlen(useString1); //returns the decimal value for the % of equal indexes in each string
}
