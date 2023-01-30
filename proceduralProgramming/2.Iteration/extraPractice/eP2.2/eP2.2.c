#include <stdio.h>

int main(void)
{
  printf("Please enter the score: ");

  int score = 0;
  scanf("%i", &score);

  if (score >= 0 && score < 50)
  {
    printf("Sorry, you have failed");
  }
  else
  {
    if (score >= 50 && score < 60)
    {
      printf("Ok, you are not bad");
    }
    else
    {
      if (score >= 60 && score < 80)
      {
        printf("That is good");
      }
      else
      {
        if (score >= 80 && score < 90)
        {
          printf("Very good");
        }
        else
        {
          if (score >= 90 && score < 101)
          {
            printf("You are Excellent");
          }
        }
      }
    }
  }
  return 0;
}
