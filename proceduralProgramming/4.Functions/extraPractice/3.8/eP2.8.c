#include <stdio.h>
#include <stdlib.h>
int addElements(int arr1[],int arr2[],int arrLength, int retIndex);


int main(void)
{
  int arrayLengths;
  printf("Please input the length you want the arrays to be: ");
  scanf("%i", &arrayLengths);

  int firstArray[arrayLengths];
  int secondArray[arrayLengths];

  for (int i = 0; i < arrayLengths; i++)
  {
    int nextElement;
    printf("Please enter the next item in array 1: ");
    scanf("%i", &nextElement);
    firstArray[i] = nextElement;
  }

  printf("Now we will fill out array 2\n");
  for (int i = 0; i < arrayLengths; i++)
  {
    int nextElement;
    printf("Please enter the next item in array 2: ");
    scanf("%i", &nextElement);
    secondArray[i] = nextElement;
  }
  for (int i = 0; i < arrayLengths; i++)
    printf("The resulting value at index %i is %i\n",i, addElements(firstArray, secondArray, arrayLengths, i));

  return 0;
}


int addElements(int arr1[],int arr2[],int arrLength, int retIndex)
{
  int retArray[arrLength];

  for (int i = 0; i < arrLength; i++)
  {
    retArray[i] = arr1[i] + arr2[i];
  }

  return retArray[retIndex];
}
