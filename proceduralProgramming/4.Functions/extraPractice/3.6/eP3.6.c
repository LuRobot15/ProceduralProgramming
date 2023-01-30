#include <stdio.h>
double mean(double arr[],int arrLength);


int main(void)
{
  double myArray[25];
  int noElements = 0;

  for (int i = 0; i < 25; i++)
  {
    double nextElement;
    printf("please enter a real number or -99 if you are done adding to the list: ");
    scanf("%lf", &nextElement);

    if (nextElement == -99)
      break;
    else
    {
      myArray[i] = nextElement;
      noElements++;
    }
  }
  printf("the mean of the inputted numbers is %lf\n", mean(myArray, noElements));

  return 0;
}


double mean(double arr[], int arrLength)
{
  double elementTotal;
  for (int i = 0; i < arrLength; i++)
  {
    elementTotal += arr[i];
  }
  return elementTotal / arrLength;
}
