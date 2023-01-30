#include <stdio.h>

int main()
{
  int a[10];
  int n;
  printf("how many numbers are there in the sequence: ");
  scanf("%i", &n);

  // read the sequence
  printf("please enter the sequence:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%i", &a[i]);
  }

  //print the sequence backwards
  printf("the sequence backwards is:\n");
  for (int i = n - 1; i >= 0; i--)
  {
    printf("%i , ", a[i]);
  }

  return 0;
}
