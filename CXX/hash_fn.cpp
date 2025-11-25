/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <cstddef>

/**
 * @brief Compute custom integer hash using multiplication and modulo.
 *
 * Uses a prime multiplier to achieve better distribution.
 *
 * @param key The integer key.
 * @param m   Table size (must be > 0)
 * @return Hash index [0, m-1], or -1 if input is invalid.
 */

int myHashInt(int key, int m) {
    if (m <= 0) {
        return -1;
    }

    const unsigned int knuth = 2654435761U;
    unsigned int ukey = static_cast<unsigned int>(key);
    unsigned int hash = (ukey * knuth) % static_cast<unsigned int>(m);

    return static_cast<int>(hash);
}

int myHashString(const std::string& str, int m) {
    if (m <= 0) {
        return -1;
    }

    unsigned long hash = 5381UL;
    for (unsigned char c : str) {
        hash = ((hash << 5) + hash) + static_cast<unsigned long>(c); /* hash * 33 + c */
    }

    return static_cast<int>(hash % static_cast<unsigned long>(m));
}
