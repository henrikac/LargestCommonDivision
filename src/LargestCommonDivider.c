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
  int num_one = 0, num_two = 0, highest_num = 0, lowest_num = 0;

  /* prompts user for two integers */
  while (true)
  {
    printf("Enter two positive numbers: ");
    scanf(" %d %d", &num_one, &num_two);

    /* checking if input is positive integers */
    if (num_one > 0 && num_two > 0)
    {
      if (num_one > num_two)
      {
        highest_num = num_one;
        lowest_num = num_two;
      }
      else
      {
        highest_num = num_two;
        lowest_num = num_one;
      }

      break;
    }

    printf("\nPlease only enter positive numbers\n");
  }

  printf("Highest number = %d\nLowest number = %d", highest_num, lowest_num);

  return EXIT_SUCCESS;
}