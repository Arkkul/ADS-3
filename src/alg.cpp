// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t current = num;
    uint64_t max_value = num;

    while (current != 1) {
        if (current % 2 == 0) {
            current /= 2;
        }else {
            current = 3 * current + 1;
        }

        if (current > max_value) {
            max_value = current;
        }
    }

    return max_value;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        }else {
            num = 3 * num + 1;
        }
        ++length;
    }

    return length;
}

unsigned int seqCollatz(unsigned int* maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    uint64_t best_num = lbound;
    unsigned int best_len = 0;

    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int len = collatzLen(i);

        if (len > best_len) {
            best_len = len;
            best_num = i;
        }
    }

    if (maxlen != nullptr) {
        *maxlen = best_len;
    }

    return static_cast<unsigned int>(best_num);
}
