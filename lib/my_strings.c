/**
 * @Author: Engeryu
 * @Date:   2018-05-03 09:18:49
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 22:36:02
 * @Description: Implementation of the my_strings library.
 *               This library provides a set of functions for string manipulation,
 *               including:
 *                 - Calculating the length of a string.
 *                 - Copying strings (full and partial).
 *                 - Comparing strings and comparing strings with a custom delimiter.
 *                 - Reversing a string.
 *                 - Duplicating a string by allocating the necessary memory.
 *                 - Concatenating strings (full and up to n characters).
 *                 - Searching for a substring within a string.
 */

#include <stdlib.h>

int my_strlen(const char *str)
{
    int length = 0;
    if (str == NULL)
    {
        return 0;
    }
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return dest;
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    if (i == n)
    {
        return 0;
    }
    return s1[i] - s2[i];
}

int my_strcmpchar_v1(const char *s1, const char *s2, char c)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] != c && s2[i] != c)
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    if (s1[i] == c && s2[i] == c)
    {
        return 0;
    }
    return s1[i] - s2[i];
}

int my_strcmpchar_v2(const char *s1, const char *s2, char c)
{
    int i = 0, j = 0;

    // Loop while both strings have remaining characters.
    while (s1[i] != '\0' && s2[j] != '\0')
    {
        // Skip 'c' in s1.
        while (s1[i] == c)
        {
            i++;
        }
        // Skip 'c' in s2.
        while (s2[j] == c)
        {
            j++;
        }
        // If one string ends after skipping, break.
        if (s1[i] == '\0' || s2[j] == '\0')
        {
            break;
        }
        if (s1[i] != s2[j])
        {
            return s1[i] - s2[j];
        }
        i++;
        j++;
    }
    // Skip any trailing 'c' characters at the end.
    while (s1[i] == c)
    {
        i++;
    }
    while (s2[j] == c)
    {
        j++;
    }
    return s1[i] - s2[j];
}

char *my_reverse_str(char *str)
{
    int len = my_strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

char *my_strdup(const char *src)
{
    int length = my_strlen(src);
    char *dup = malloc(sizeof(char) * (length + 1));
    if (dup == NULL)
    {
        return NULL;
    }
    my_strcpy(dup, src);
    return dup;
}

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    while (src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char *my_strncat(char *dest, const char *src, int n)
{
    int dest_len = my_strlen(dest);
    int i = 0;
    while (i < n && src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char *my_strstr(const char *haystack, const char *needle)
{
    int i, j;
    if (*needle == '\0')
    {
        return (char *)haystack;
    }
    for (i = 0; haystack[i] != '\0'; i++)
    {
        for (j = 0; needle[j] != '\0' && haystack[i + j] == needle[j]; j++)
        {
            ; // Continue matching
        }
        if (needle[j] == '\0')
        {
            return (char *)(haystack + i);
        }
    }
    return NULL;
}