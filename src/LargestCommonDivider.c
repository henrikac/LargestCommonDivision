/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Coming soon...
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int main(void)
{
  int highest_num = 0, lowest_num = 0;
  int largest_common = 0;
  int i;

  /* prompts user for two integers */
  while (true)
  {
    printf("Enter two positive numbers: ");
    scanf(" %d %d", &highest_num, &lowest_num);

    /* checking if input is positive integers */
    if (highest_num > 0 && lowest_num > 0)
    {
      /* swapping values if lowest_num > highest_num */
      if (lowest_num > highest_num)
      {
        int temp = lowest_num;
        lowest_num = highest_num;
        highest_num = temp;
      }

      break;
    }

    printf("\nPlease only enter positive numbers\n");
  }

  printf("Highest number = %d\nLowest number = %d", highest_num, lowest_num);

  for (i = 1; i <= lowest_num; i++)
  {
    if (highest_num % i == 0 && lowest_num % i == 0)
    {
      largest_common = i;
    }
  }

  printf("\nLargest common divider = %d", largest_common);

  return EXIT_SUCCESS;
}