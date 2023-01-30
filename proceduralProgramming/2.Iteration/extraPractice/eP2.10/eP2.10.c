#include <stdio.h>

int main (void)
{
  int inpNumber;                          //takes an integer input from the user and
  printf("please enter an integer: ");    //stores it as inpNumber
  scanf("%i", &inpNumber);

  int placeHolder = inpNumber;    //placeHolder will be changed in the loop
  int digitsInInp = 0;    //stores the amount of digits the inputted number
  int digitStore[10];   //array storing the indevidual digits

  for (int multiplier = 10; inpNumber % (multiplier/10) != inpNumber; multiplier = multiplier * 10)
  {
    int currentInt = placeHolder % multiplier;    //stores the next multiple of 10 in the
                                              //inputted number as currentInt

    placeHolder = placeHolder - currentInt;     //removes the digit being isolated
                                                //from the inputted number

    currentInt = currentInt / (multiplier/10);     //gets the digit being isolated on its own

    digitStore[digitsInInp] = currentInt;

    digitsInInp++;
  }

  int lengthOfInp = (sizeof(digitStore) / sizeof(digitStore[0])) -1;    //finds the length of
                                                                        // the array by finding the data size of the array devided by the data size of one element.

  while (digitsInInp > 0)
  {
    printf("%i, ", digitStore[digitsInInp - 1]);          //prints the elements
    digitsInInp--;
  }
  return 0;
}
