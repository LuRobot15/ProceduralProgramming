#include <stdio.h>

int main(void)
{
  int inpMark;    //Lines 5-7 prompt the user to enter the mark of the first student and
  printf("Please input the first student's mark: ");   //stores the value as inpMark
  scanf("%i", &inpMark);

  int count = 0;    //Records the number of students who's mark has been entered

  int totalMark = 0; //Stores the sum of all students marks

  int hMark = 0;    //Stores the highest mark
  int lMark = 101;    //Stores the lowest mark

  int passStudents = 0;   //Stores the number of students who've passed


  while (inpMark >= 0)
  {
    if (inpMark > 100)    //Checks if the input is within the valid mark range and asks
    {                     //the user for another input if it doesn't.
      printf("That is not a valid input.");
      printf("Please enter a valid mark: ");
      scanf("%i", &inpMark);
      continue;
    }

    count++;    //Increments the count for every posative mark entered

    if (inpMark > hMark)    //Compares the latest input mark with the current highest
    {                       //mark and makes the neccessary changes
      hMark = inpMark;
    }

    if (inpMark < lMark)    //Compares latest input with the current lowest mark
    {                       //and makes neccessary changes
      lMark = inpMark;
    }

    totalMark = totalMark + inpMark;    //Increases the total marks to include the
                                        //latest input

    if (inpMark >= 50)
    {
      passStudents++;   //increments the numberof students who passed if the latest
                        //input was a pass mark
    }

    printf("Please enter the next students mark or if you have no more marks to enter, enter a negative number: ");
    scanf("%i", &inpMark);    //prompts the user to enter the next student's mark
    continue;                 //and restarts the loop
  }

  printf("The total number of students is %i.\n", count);   //prints total marks entered
  printf("the adverage mark was: %i\n", totalMark/count);   //prints adverage mark
  printf("the highest mark was: %i\n", hMark);    //prints highest mark
  printf("the lowest mark was: %i\n", lMark);   //prints lowest mark
  printf("the pass rate was: %lf percent\n", ((double) passStudents / count) * 100); //prints pass rate

  return 0;
}
