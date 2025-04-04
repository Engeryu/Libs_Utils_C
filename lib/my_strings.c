/**
 * @Author: Engeryu
 * @Date:   2018-05-03 09:18:49
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-04-04 18:00:14
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

// Macros to check for NULL
#define CHECK_NULL_1(ptr) (((ptr) == NULL) ? 1 : 0)
#define CHECK_NULL_2(ptr1, ptr2) (((ptr1) == NULL || (ptr2) == NULL) ? 1 : 0)

// Utility function for safe memory allocation
void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        return NULL; // Allocation failure
    }
    return ptr;
}

// Refactored functions
unsigned int my_strlen(const char *str) {
    if (CHECK_NULL_1(str)) {
        return 0; // Invalid pointer
    }

    unsigned int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

char *my_strcpy(char *dest, const char *src, size_t dest_size) {
    if (CHECK_NULL_2(dest, src)) {
        return NULL; // Invalid pointers
    }

    size_t i = 0;
    while (src[i] != '\0' && i < dest_size - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Proper null termination
    return dest;
}

char *my_strncpy(char *dest, const char *src, size_t dest_size) {
    if (CHECK_NULL_2(dest, src)) {
        return NULL; // Invalid pointers
    }

    size_t i = 0;
    while (i < dest_size && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    while (i < dest_size) { // Fill remaining space with '\0'
        dest[i] = '\0';
        i++;
    }
    return dest;
}

int my_strcmp(const char *s1, const char *s2) {
    if (CHECK_NULL_2(s1, s2)) {
        return -1; // Invalid pointers
    }

    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int my_strncmp(const char *s1, const char *s2, size_t n) {
    if (CHECK_NULL_2(s1, s2)) {
        return -1; // Invalid pointers
    }

    size_t i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        i++;
    }
    return (i == n) ? 0 : (unsigned char)s1[i] - (unsigned char)s2[i];
}

int my_strcmpchar_v1(const char *s1, const char *s2, char c) {
    if (CHECK_NULL_2(s1, s2)) {
        return -1; // Invalid pointers
    }

    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] != c && s2[i] != c) {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        i++;
    }
    return (s1[i] == c && s2[i] == c) ? 0 : (unsigned char)s1[i] - (unsigned char)s2[i];
}

int my_strcmpchar_v2(const char *s1, const char *s2, char c) {
    if (CHECK_NULL_2(s1, s2)) {
        return -1; // Invalid pointers
    }

    size_t i = 0, j = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        while (s1[i] == c) i++;
        while (s2[j] == c) j++;
        if (s1[i] != s2[j]) {
            return (unsigned char)s1[i] - (unsigned char)s2[j];
        }
        if (s1[i] != '\0') i++;
        if (s2[j] != '\0') j++;
    }
    while (s1[i] == c) i++;
    while (s2[j] == c) j++;
    return (unsigned char)s1[i] - (unsigned char)s2[j];
}

char *my_reverse_str(const char *str) {
    if (CHECK_NULL_1(str)) {
        return NULL; // Invalid pointer
    }

    int len = my_strlen(str);
    char *reversed = safe_malloc(sizeof(char) * (len + 1));
    if (reversed == NULL) {
        return NULL; // Memory allocation failure
    }

    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

char *my_strdup(const char *src) {
    if (CHECK_NULL_1(src)) {
        return NULL; // Invalid input
    }

    int length = my_strlen(src);
    char *dup = safe_malloc(sizeof(char) * (length + 1));
    if (dup == NULL) {
        return NULL; // Memory allocation failure
    }

    for (int i = 0; i < length; i++) {
        dup[i] = src[i];
    }
    dup[length] = '\0';
    return dup;
}

char *my_strcat(char *dest, const char *src) {
    if (CHECK_NULL_2(dest, src)) {
        return NULL; // Invalid pointers
    }

    int dest_len = my_strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char *my_strstr(const char *haystack, const char *needle) {
    if (CHECK_NULL_2(haystack, needle)) {
        return NULL; // Invalid pointers
    }
    if (*needle == '\0') {
        return (char *)haystack; // Empty needle matches everything
    }

    for (int i = 0; haystack[i] != '\0'; i++) {
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }
        if (needle[j] == '\0') {
            return (char *)(haystack + i);
        }
    }
    return NULL;
} 