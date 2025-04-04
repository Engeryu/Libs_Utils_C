/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:05:23
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 21:48:04
 * @Description: Header file for the my_numbers library.
 *               This library provides functions for performing number 
 *               manipulations including converting a string to an integer 
 *               (my_atoi), converting an integer to a string (my_itoa), and 
 *               swapping two integer values (my_swap).
 */

#ifndef MY_NUMBERS_H
#define MY_NUMBERS_H

#include <stdlib.h>

/*
* Converts a string to an integer.
* Handles optional leading whitespace and an optional sign.
*/
int my_atoi(const char *str);

/*
* Converts an integer to a null-terminated string.
* The returned string is allocated dynamically and should be freed by the caller.
*/
char *my_itoa(int n);

/*
* Swaps the values of the two integers pointed to by a and b.
*/
void my_swap(int *a, int *b);

#endif // MY_NUMBERS_H