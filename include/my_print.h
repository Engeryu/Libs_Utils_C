/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:00:38
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 21:50:18
 * @Description: Header file for the my_print library.
 *               This library provides functions to write characters, strings,
 *               and integers to the standard output.
 *               
 *               Functions included:
 *               - my_putchar: Writes a single character.
 *               - my_putstr : Writes a null-terminated string.
 *               - my_putnbr : Writes an integer, handling negative values appropriately.
 */

#ifndef MY_PRINT_H
#define MY_PRINT_H

#include <unistd.h>

/*
* Writes a single character to the standard output.
*/
void my_putchar(char c);

/*
* Writes a null-terminated string to the standard output.
*/
void my_putstr(const char *str);

/*
* Writes an integer to the standard output.
* Handles negative numbers correctly.
*/
void my_putnbr(int n);

#endif // MY_PRINT_H