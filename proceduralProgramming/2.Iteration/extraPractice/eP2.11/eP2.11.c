#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int inpNumber = 0;    //variable the input is assigned to

  while(1 == 1)
  {
    int number1 = rand() % (10 + 1 - 1) + 1;    //generates a reandom number between 1 and 10
    int number2 = rand() % (10 + 1 - 1) + 1;

    printf("What is %i multiplied by %i?\n", number1, number2);   //prompts user to enter number 1 times number 2

    for(int i = 0; i < 4; i++)
    {

      scanf("%i", &inpNumber);    //accepts users answer and stores it

      if (inpNumber == -99)   //programm exit condition
      {
        exit(0);
      }

      if (inpNumber == number1 * number2)   //what happens if users input is correct
      {
        printf("good\n");
        break;    //breaks current loop so new numbers are given
      }
      else
      {
        if(i + 1 == 3)    //if too many trials have taken place
        {
          printf("Too many trials, the correct answer is: %i\n", number1 * number2);
          break;
        }
        else
        {
          printf("wrong answer, try again: ");    //gets user to try again if their answer is wrong
          continue;
        }
      }
    }
  }

  return 0;
}
