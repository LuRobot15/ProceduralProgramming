#include <stdio.h>
int searchArray (int arr[], int arrayLength, int searchItem);


int main(void)
{
  int myArray[25];
  int noElements = 0;
  for (int i = 0; i < 25; i++)
  {
    int nextElement;
    printf("Please enter the next item you want added to the array or -99 if you are done: ");
    scanf("%i", &nextElement);
    if (nextElement == -99)
      break;
    else
    {
      myArray[i] = nextElement;
      noElements++;
    }
  }

    printf("please enter the number you want to search for: ");
    int searchItem;
    scanf("%i", &searchItem);

    if (searchArray(myArray, noElements, searchItem) == -1)
      printf("That is not an iotem in the array\n");
    else
      printf("the item you searched for is at index %i\n", searchArray(myArray, noElements, searchItem));

  return 0;
}


int searchArray(int arr[], int arrayLength, int searchItem)
{
  int i = 0;
  while (i < arrayLength)
  {
    if (arr[i] == searchItem)
      break;
    else
    {
      i++;
      continue;
    }
  }

  if (arr[i] == searchItem)
    return i;
  else
    return -1;
}
