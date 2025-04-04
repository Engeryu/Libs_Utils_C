/**
 * @Author: Engeryu
 * @Date:   2018-05-04 09:23:02
 * @Last Modified by:   Engeryu
 * @Last Modified time: 2025-03-30 22:39:44
 * @Description: Implementation of the my_memory library.
 *               This library provides basic memory manipulation functions, including:
 *               - my_memset: Fills the first n bytes of a memory area with a specified byte.
 *               - my_memcpy: Copies n bytes from one memory area to another.
 *               Note: The memory areas must not overlap when using my_memcpy.
 */

#include "my_memory.h"

/*
* Fills the first n bytes of the memory area pointed to by s with the constant byte c.
* Returns a pointer to the memory area s.
*/
void *my_memset(void *s, int c, size_t n)
{
    unsigned char *ptr = s;
    
    for (size_t i = 0; i < n; i++)
    {
        ptr[i] = (unsigned char)c;
    }
    return s;
}

/*
* Copies n bytes from memory area src to memory area dest.
* The memory areas must not overlap.
* Returns a pointer to dest.
*/
void *my_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *dest_ptr = (unsigned char *)dest;
    const unsigned char *src_ptr = (const unsigned char *)src;
    for (size_t i = 0; i < n; i++)
    {
        dest_ptr[i] = src_ptr[i];
    }
    return dest;
}