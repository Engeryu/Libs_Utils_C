/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:07:48
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 22:22:18
 * @Description: Implementation of the my_numbers library.
 *               This library provides functions for number manipulation, including:
 *               - my_atoi: Converts a string to an integer, handling optional leading
 *                          whitespace and sign.
 *               - my_itoa: Converts an integer to a null-terminated string.
 *                          The result is allocated dynamically and should be freed
 *                          by the caller.
 *               - my_swap: Swaps the values of two integers.
 */

#include "my_numbers.h"

int my_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    
    // Skip leading whitespace characters
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
        str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
    {
        i++;
    }
    // Check for optional sign
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            sign = -1;
        }
        i++;
    }
    // Convert digits to integer value
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

char *my_itoa(int n)
{
    int temp = n;
    int len = 0;
    int negative = 0;
    
    if (n < 0)
    {
        negative = 1;
        temp = -n;
    }
    else
    {
        temp = n;
    }
    if (n == 0)
    {
        len = 1;
    }
    // Count number of digits
    while (temp != 0)
    {
        len++;
        temp /= 10;
    }
    if (negative)
    {
        len++;  // For the '-' sign
    }
    char *str = malloc(sizeof(char) * (len + 1));

    if (str == NULL)
    {
        return NULL;
    }
    str[len] = '\0';
    temp = (negative) ? -n : n;

    for (int i = len - 1; i >= 0; i--)
    {
        str[i] = (temp % 10) + '0';
        temp /= 10;
        
        if (i == 0 && negative)
        {
            str[0] = '-';
        }
    }
    return str;
}

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} 