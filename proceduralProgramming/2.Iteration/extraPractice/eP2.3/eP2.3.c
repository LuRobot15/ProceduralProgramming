#include <stdio.h>

int main(void)
{
  printf("Please input an integer: ");

  int n;
  scanf("%i", &n);

  printf("Please input anoteher integer: ");

  int m;
  scanf("%i", &m);

  printf("the odd numbers between the two inputs are: ");   // tells the user what is being printed
  if (n < m)
  {
    if (n % 2 == 1)   // if n is odd
    {
      while(n <= m)   //loop traverses and prints every odd number between n and m
      {
        printf("%i, ", n);
        n = n + 2;
      }
    }
    else
    {
      n = n + 1;    // makes n into the nearest odd number if it isn't already
      while (n <= m)    //loop traverses and prints every odd number between n and m
      {
        printf("%i, ", n);
        n = n+ 2;
      }
    }
  }
  else
  {
    if (m % 2 == 1)   // if n is odd
    {
      while(m <= n)   //loop traverses and prints every odd number between n and m
      {
        printf("%i, ", m);
        m = m + 2;
      }
    }
    else
    {
      m = m + 1;    // makes n into the nearest odd number
      while (m <= n)    //loop traverses and prints every odd number between n and m
      {
        printf("%i, ", m);
        m = m + 2;
      }
    }
  }
  return 0;
}
