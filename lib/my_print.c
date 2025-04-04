/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:02:16
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-04-04 18:04:17
 * @Description: Implementation of the my_print library.
 *               This library provides functions for printing output:
 *               - my_putchar: writes a single character to the standard output.
 *               - my_putstr: writes a null-terminated string to the standard output.
 *               - my_putnbr: writes an integer to the standard output, handling negative values.
 */

#include "my_print.h"
#include <unistd.h>

// Static buffer and index for buffered output
static char buffer[BUFFER_SIZE];
static int buffer_index = 0;

// Writes a character to the standard output using buffered output.
void my_putchar(char c)
{
    buffer[buffer_index++] = c;

    // Flush the buffer if full or a newline is encountered
    if (buffer_index == BUFFER_SIZE || c == '\n')
    {
        write(1, buffer, buffer_index);
        buffer_index = 0; // Reset the buffer index
    }
}

//Flushes the internal buffer, ensuring all buffered data is written to the output.
void flush_buffer(void)
{
    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
        buffer_index = 0; // Reset the buffer index
    }
}

// Writes a null-terminated string to the standard output.
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
 * Handles negative numbers correctly.
 */
void my_putnbr(int n)
{
    if (n < 0)
    {
        my_putchar('-');
        /* Handle the most negative number (-2147483648) */
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