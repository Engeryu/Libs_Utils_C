/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:34:12
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 22:40:18
 * @Description: Implementation of my_charsutils library.
 *               This library provides utility functions for:
 *               - Checking if an integer is negative (prints 'N' for negative, 'P' for positive).
 *               - Splitting a string into tokens based on a delimiter.
 *               - Converting characters to lowercase and uppercase.
 */

#include "my_charsutils.h"
#include "my_print.h"   // For using my_putchar in my_isneg
#include <stdlib.h>

/*
* Checks if the provided integer is negative.
* If the number is negative, prints 'N'; otherwise, prints 'P'.
*/
void my_isneg(int nb)
{
    if (nb < 0)
        my_putchar('N');
    else
        my_putchar('P');
}

/*
* Splits the input string into an array of strings based on the specified delimiter.
* Returns a NULL-terminated array of strings.
* Note: Consecutive delimiters are treated such that empty tokens are ignored.
*/
char **my_split(const char *str, char delimiter)
{
    if (str == NULL)
        return NULL;
    
    int tokenCount = 0;
    int i = 0;
    int inToken = 0;
    
    // Count the number of tokens (non-empty substrings)
    while (str[i] != '\0')
    {
        if (str[i] != delimiter && inToken == 0)
        {
            inToken = 1;
            tokenCount++;
        }
        else if (str[i] == delimiter)
        {
            inToken = 0;
        }
        i++;
    }
    
    // Allocate memory for the array of string pointers (+1 for the NULL terminator)
    char **result = malloc(sizeof(char *) * (tokenCount + 1));
    if (result == NULL)
        return NULL;
    
    int token_index = 0;  // Index in the result array
    int token_start = 0;
    inToken = 0;
    i = 0;
    
    // Extract tokens from the string
    while (str[i] != '\0')
    {
        if (str[i] != delimiter && inToken == 0)
        {
            inToken = 1;
            token_start = i;
        }
        // When the delimiter is found or end of string is reached, and we're in a token:
        if ((str[i] == delimiter || str[i + 1] == '\0') && inToken)
        {
            int token_end = (str[i] == delimiter) ? i : i + 1;
            int token_length = token_end - token_start;
            
            // Allocate memory for the token string (+1 for '\0')
            result[token_index] = malloc(sizeof(char) * (token_length + 1));
            if (result[token_index] == NULL)
            {
                // Free previously allocated memory if allocation fails
                for (int j = 0; j < token_index; j++)
                    free(result[j]);
                free(result);
                return NULL;
            }
            // Copy the token into the allocated memory
            for (int j = 0; j < token_length; j++)
            {
                result[token_index][j] = str[token_start + j];
            }
            result[token_index][token_length] = '\0';
            token_index++;
            inToken = 0;
        }
        i++;
    }
    result[token_index] = NULL;  // End marker for the array
    return result;
}

/*
* Converts a character to lowercase.
* If the character is an uppercase letter, returns its lowercase equivalent.
* Otherwise, returns the character unchanged.
*/
char my_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

/*
* Converts a character to uppercase.
* If the character is a lowercase letter, returns its uppercase equivalent.
* Otherwise, returns the character unchanged.
*/
char my_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
} 