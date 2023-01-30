#include <stdio.h>

int main(void)
{
  int inpNumber;    //asks the user for an integer input and stores it as inpNumber
  printf("Please input the number you want to be reversed: ");
  scanf("%i", &inpNumber);

  int placeHolder = inpNumber;    //a version of inpNumber that we can change
  int reversedNumber = 0;   //where our answer will be stored
  for(int multiplier = 10; ; multiplier = multiplier * 10)
  {
    if (inpNumber % (multiplier/10) == inpNumber)   //Terminating condition for when
    {                                               //there are no more digits to be added
      break;                                        //to the reversed number
    }

    int leftOver = placeHolder % multiplier;    //gets the digit on its own

    placeHolder = placeHolder - leftOver;   //removes the digit being added to the
                                            //reversedNumber from the placeHolder

    leftOver = leftOver / (multiplier/10);    //reduces the remainder down to a
                                              //single digit

    reversedNumber = (reversedNumber * 10) + leftOver;    //adds the digit to the end
                                                          //of the reversed number
  }

  printf("%i reversed is %i\n", inpNumber, reversedNumber);

  return 0;
}
