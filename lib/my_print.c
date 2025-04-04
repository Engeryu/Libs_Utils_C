/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:02:16
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 22:21:49
 * @Description: Implementation of the my_print library.
 *               This library provides functions for printing output:
 *               - my_putchar: writes a single character to the standard output.
 *               - my_putstr: writes a null-terminated string to the standard output.
 *               - my_putnbr: writes an integer to the standard output, handling negative values.
 */

#include "my_print.h"
#include <unistd.h>

/*
* Writes a character to the standard output.
*/
void my_putchar(char c)
{
    write(1, &c, 1);
}

/*
* Writes a null-terminated string to the standard output.
*/
void my_putstr(const char *str)
{
    while (*str)
    {
        my_putchar(*str);
        str++;
    }
}

/*
* Writes an integer to the standard output.
* This function handles negative numbers.
*/
void my_putnbr(int n)
{
    if (n < 0)
    {
        my_putchar('-');
        /* Handle the most negative number */
        if (n == -2147483648)
        {
            my_putstr("2147483648");
            return;
        }
        n = -n;
    }
    if (n >= 10)
    {
        my_putnbr(n / 10);
    }
    my_putchar((n % 10) + '0');
}