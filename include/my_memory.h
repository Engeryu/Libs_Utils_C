/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:20:16
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 22:39:29
 * @Description: Header file for the my_memory library.
 *               This library provides basic memory manipulation functions,
 *               including:
 *               - my_memset: Fills a memory area with a constant byte.
 *               - my_memcpy: Copies a block of memory from one area to another.
 */

#ifndef MY_MEMORY_H
#define MY_MEMORY_H

#include <stdlib.h>

/*
* Fills the first n bytes of the memory area pointed to by s with the constant byte c.
* Returns a pointer to the memory area s.
*/
void *my_memset(void *s, int c, size_t n);

/*
* Copies n bytes from the memory area src to the memory area dest.
* The memory areas must not overlap.
* Returns a pointer to dest.
*/
void *my_memcpy(void *dest, const void *src, size_t n);

#endif // MY_MEMORY_H