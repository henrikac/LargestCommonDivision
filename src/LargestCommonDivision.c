/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * User enters two numbers positive numbers
 * the program then returns the largest division of the two numbers
 * 
 * Examples:
 * 
 * 21 18   should return  3
 * 315 120 should return 15
 * 408 456 should return 24
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

#define NEGATIVE_NUM -1

typedef enum { false, true } bool;

bool is_prime(int num);

int main(void)
{
  int highest_num = 0, lowest_num = 0;
  int largest_common = 0;
  int i; /* ANSI C89: for-loop */

  /* clear the console */
  system(CLEAR);

  printf("========================");
  printf("\nLargest Common Division\n");
  printf("========================\n\n");

  /* 
   * prompts user for two integers 
   * keeps prompting until user enters two positive numbers
   * and exits if user enters a negative number or a char
  */
  while (true)
  {
    printf("Enter two positive numbers: ");

    /* checks if user input is valid (a number) */
    if (scanf(" %d %d", &highest_num, &lowest_num) != 2)
    {
      printf("\nInvalid input!\n");
      return EXIT_FAILURE;
    }
    fflush(stdin);

    /* 
     * checks if user enters a negative number
     * and exists if a negative number is entered
    */
    if (highest_num < 0 || lowest_num < 0)
    {
      printf("\nPlease only enter positive numbers\n");
      return NEGATIVE_NUM;
    }

    /* swaps values if lowest_num > highest_num */
    if (lowest_num > highest_num)
    {
      int temp = lowest_num;
      lowest_num = highest_num;
      highest_num = temp;
    }

    printf("\nHighest number = %d\nLowest number = %d", highest_num, lowest_num);

    /*
     * checks if one of the numbers entered is 0
     * and restart loop if true
    */
    if (highest_num == 0 || lowest_num == 0)
    {
      bool both_0 = highest_num == 0 && lowest_num == 0 ? true : false;
      largest_common = 0;
      printf("\n%s is 0\n\n", both_0 ? "Both numbers" : "One of the numbers");
      continue;
    }

    /* checks if user entered a prime number */
    if (is_prime(highest_num) || is_prime(lowest_num))
    {
      bool high_divby_low = highest_num % lowest_num == 0;
      largest_common = high_divby_low ? lowest_num : 1;

      if (is_prime(highest_num) && is_prime(lowest_num))
        printf("\nBoth numbers are prime numbers");
      else
        printf("\n%d is a prime number and %d / %d %s",
          is_prime(highest_num) ? highest_num : lowest_num,
          highest_num,
          lowest_num,
          high_divby_low ? "returns a whole number" : "does not return a whole number");
    }
    else /* if no prime number entered - start check each number <= lowest_num */
    {
      for (i = 1; i <= lowest_num; i++)
      {
        if (highest_num % i == 0 && lowest_num % i == 0)
        {
          largest_common = i;
        }
      }
    }

    printf("\nLargest common division = %d\n\n", largest_common);
  }

  return EXIT_SUCCESS;
}

bool is_prime(int num)
{
  int i;

  if (num <= 3)
    return true;
  else if (num % 2 == 0 || num % 3 == 0)
    return false;
  
  for (i = 3; i <= sqrt(num); i += 2)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}