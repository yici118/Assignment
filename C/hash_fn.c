/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/22: Added full integer-hash with error handling

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"

/**
 * @brief Compute custom integer hash using multiplication and modulo.
 *
 * This hash function uses a simple multiplication method with a prime
 * multiplier to improve uniformity of key distribution.
 *
 * @param key The integer key to hash.
 * @param m   The table size (must be > 0).
 * @return Hash index [0, m-1], or -1 if input is invalid.
 */
int myHashInt(int key, int m) {
    if (m <= 0) return -1; // invalid table size

    const unsigned int prime = 2654435761U; // Knuth's multiplicative constant
    unsigned int ukey = (unsigned int)key;  // treat as unsigned
    unsigned int hash = (ukey * prime) % m;

    return (int)hash;
}

/**
 * @brief Compute a hash value for a string key.
 *
 * This function computes a hash index for a string by iterating
 * through each character and accumulating a hash value. The current
 * implementation uses a simple multiplier-based accumulation.
 *
 * @param str The input string to hash. Must not be NULL.
 * @param m   The table size (must be > 0).
 * @return The hash index on success, or -1 on invalid input.
 */

int myHashString(const char* str, int m) {
    if (str == NULL || m <= 0) {
        return -1; /* invalid input */
    }

    unsigned long hash = 5381UL;
    const unsigned char *u = (const unsigned char *) str;

    while (*u) {
        /* hash * 33 + c */
        hash = ((hash << 5) + hash) + (unsigned long)(*u);
        u++;
    }

    return (int)(hash % (unsigned long)m);
}
