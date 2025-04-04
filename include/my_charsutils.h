/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:27:34
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 22:40:03
 * @Description: Header file for my_charsutils library.
 *               This library provides utility functions for:
 *               - Checking if a number is negative (prints 'N' or 'P').
 *               - Splitting a string using a given delimiter.
 *               - Converting characters to lowercase and uppercase.
 */

#ifndef MY_CHARSUTILS_H
#define MY_CHARSUTILS_H

/*
* Checks if the provided integer is negative.
* If the number is negative, the function prints 'N'; otherwise, it prints 'P'.
*/
void my_isneg(int nb);

/*
* Splits the input string into an array of strings using the specified delimiter.
* Returns a NULL-terminated array of strings.
* Note: Consecutive delimiters are treated according to your implementation.
*/
char **my_split(const char *str, char delimiter);

/*
* Converts a character to lowercase.
* If the character is an uppercase letter, returns its lowercase equivalent.
* Otherwise, returns the character unchanged.
*/
char my_tolower(char c);

/*
* Converts a character to uppercase.
* If the character is a lowercase letter, returns its uppercase equivalent.
* Otherwise, returns the character unchanged.
*/
char my_toupper(char c);

#endif // MY_CHARSUTILS_H