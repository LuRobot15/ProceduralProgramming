#include <stdio.h>
int highestElement(int arr[],int nOElements);


int main(void)
{
  int myArray[10];
  int elementsInArray = 0;
  for (int i = 0; i < 10; i++)
  {
    printf("please enter an item you want in the list or -99 if you are done: ");
    int nextElement;
    scanf("%i", &nextElement);
    if (nextElement == -99)
      break;
    else
    {
      myArray[i] = nextElement;
      elementsInArray++;
    }
  }
  printf("The largest element in my array is: %i\n", highestElement(myArray, elementsInArray));

  return 0;
}


int highestElement(int arr[], int nOElements)
{
  int greatestElement = arr[0];
  for (int i = 1; i < nOElements; i++)
  {
    if (arr[i] > greatestElement)
      greatestElement = arr[i];
  }
  return greatestElement;
}
