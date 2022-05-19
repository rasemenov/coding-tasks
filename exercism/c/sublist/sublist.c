#include "sublist.h"

#include <string.h>


static int is_sublist(int *, int *, size_t, size_t);


comparison_result_t check_lists(int *first, int *second,
                                size_t first_len, size_t second_len) {
    if (!first_len || !second_len) {
        if (first_len == second_len) {
            return EQUAL;
        } else if (!first_len) {
            return SUBLIST;
        } else {
            return SUPERLIST;
        }
    }
    if (second_len > first_len) {
        if (is_sublist(second, first, second_len, first_len)) {
            return SUBLIST;
        }
    } else if (first_len > second_len) {
        if (is_sublist(first, second, first_len, second_len)) {
            return SUPERLIST;
        }
    } else {
        if (!memcmp(first, second, first_len * sizeof(int))) {
            return EQUAL;
        }
    }
    return UNEQUAL;
}


static int is_sublist(int *large, int *small,
                  size_t large_len, size_t small_len) {
    int offset = large_len - small_len;
    for (int indx = 0; indx <= offset; indx++ ) {
        if (!memcmp(large + indx, small, small_len * sizeof(int))) {
            return 1;
        }
    }
    return 0;
}
