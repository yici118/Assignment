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

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    return (int)(hash % m); // basic division method
}
