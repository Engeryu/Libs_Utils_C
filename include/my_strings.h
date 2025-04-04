/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:09:49
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 21:50:13
 * @Description: Header file for the my_strings library.
 *               This library provides functions for string manipulation,
 *               including calculating the length of a string, copying strings,
 *               comparing strings, concatenating strings, reversing and duplicating strings,
 *               as well as searching for substrings.
 */

#ifndef MY_STRINGS_H
#define MY_STRINGS_H

/*
* Calculates the length of a string.
* Returns 0 if the pointer is NULL.
*/
int my_strlen(const char *str);

/*
* Copies the source string into the destination string.
* Assumes that dest has enough allocated memory.
*/
char *my_strcpy(char *dest, const char *src);

/*
* Copies at most n characters from src to dest.
* If src is shorter than n characters, the remainder of dest is filled with '\0'.
*/
char *my_strncpy(char *dest, const char *src, int n);

/*
* Compares two strings s1 and s2 character by character.
* Returns the difference (positive, negative, or 0) at the first differing character.
*/
int my_strcmp(const char *s1, const char *s2);

/*
* Compares up to n characters of two strings s1 and s2.
*/
int my_strncmp(const char *s1, const char *s2, int n);

/*
* Version 1: Stop comparison when character 'c' is encountered.
*
* This function compares two strings, s1 and s2, character by character.
* The comparison stops as soon as either string reaches the character 'c' 
* (or the end of the string). If both strings reach 'c' at the same position,
* they are considered equal up to that point (returns 0).
*/
int my_strcmpchar_v1(const char *s1, const char *s2, char c);

/*
* Version 2: Skip all occurrences of character 'c' during comparison.
*
* This function compares two strings, s1 and s2, while ignoring any occurrence
* of the character 'c'. It advances the index in each string if the current
* character equals 'c'. The function then compares the next available non-'c'
* characters. It returns the difference between the first pair of non-'c'
* characters that differ, or 0 if the strings (ignoring 'c') are equal.
*/
int my_strcmpchar_v2(const char *s1, const char *s2, char c);

/*
* Reverses the given string in place.
*/
char *my_reverse_str(char *str);

/*
* Duplicates the given string by allocating sufficient memory.
*/
char *my_strdup(const char *src);

/*
* Concatenates the string src to the end of dest.
* Assumes that dest has enough allocated memory.
*/
char *my_strcat(char *dest, const char *src);

/*
* Concatenates at most n characters of src to the end of dest.
*/
char *my_strncat(char *dest, const char *src, int n);

/*
* Finds the first occurrence of the substring needle in haystack.
* Returns a pointer to the beginning of the located substring, or NULL if not found.
*/
char *my_strstr(const char *haystack, const char *needle);

#endif // MY_STRINGS_H