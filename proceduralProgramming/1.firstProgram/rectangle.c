#include <stdio.h>
int main()
{
  int Length;
  int Width;
  int Area;
  int Perimeter;
  printf("Please input the length of the field (m):");
  scanf("%i",&Length);
  printf("Please input the width of the field (m):");
  scanf("%i",&Width);
  Area = Length * Width;
  Perimeter = (Length * 2) + (Width * 2);
  printf("the field has an area of %i meters squared\n", Area);
  printf("the field has a perimeter of %i meters\n", Perimeter);
  return 0;
}
