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
 * This version includes:
 *   - error handling for invalid m (m <= 0)
 *   - normalization for negative keys
*/

int myHashInt(int key, int m) {
    // TODO: replace with your own design
     if (m <= 0) {
        return -1;   // invalid table size
    }
    int hash = key % m;
    // ensure non-negative
    if (hash < 0) {
        hash += m;
    }
    return hash;
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
    unsigned long hash = 0;
    if (str == NULL || m <= 0) {
        // invalid input
        return -1;
    }

    unsigned long hash = 0;
    const unsigned long base = 31;   // simple multiplier

    for (int i = 0; str[i] != '\0'; i++) {
        hash = hash * base + (unsigned long)str[i];
    }

    return (int)(hash % m);
}
