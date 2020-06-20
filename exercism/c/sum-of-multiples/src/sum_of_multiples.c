#include "sum_of_multiples.h"

#include <limits.h>
#include <stdbool.h>


static int min(const unsigned int *array, size_t len) {
    unsigned int min = INT_MAX;
    int indx = 0;
    for (int i = 0; i < (int)len; i++) {
        if (min > array[i]) {
            min = array[i];
            indx = i;
        }
    }
    return indx;
}


static unsigned int lcm(const unsigned int *multiples, size_t len) {
    if (len == 1) {
        return multiples[0];
    }
    bool work = true;
    int min_indx;
    unsigned int lcm[len];
    for (int i = 0; i < (int)len; i++) {
        lcm[i] = multiples[i];
    }
    while (work) {
        min_indx = min(lcm, len);
        lcm[min_indx] += multiples[min_indx];
        for (int i = 0; i < (int)len - 1; i++) {
            if (lcm[i] != lcm[i + 1]) {
                break;
            }
            if (i == (int)len - 2) {
                work = false;
            }
        }
    }
    return lcm[0];
}


static unsigned int get_mult_sum(unsigned int num, unsigned int up_to) {
    unsigned int n_times = (up_to - 1) / num;
    return num * n_times * (n_times + 1) / 2;
}


unsigned int sum_of_multiples(const unsigned int *multiples,
                              size_t len, unsigned int up_to) {
#define MAX_MULTIPLES 3
#define SUBSET_SIZE 2

    if (!multiples || len == 0 || len > MAX_MULTIPLES) {
        return 0;
    }
    int combinations[][SUBSET_SIZE] = {{0, 1}, {1, 2}, {0, 2}};
    unsigned int sum = 0, common_multiple = 0, subset[SUBSET_SIZE];
    for (int i = 0; i < (int)len; i++) {
        if (!multiples[i]) {
            continue;
        }
        sum += get_mult_sum(multiples[i], up_to);
    }
	if (len == SUBSET_SIZE) {
        common_multiple = lcm(multiples, len);
        if (common_multiple) {
            sum -= get_mult_sum(common_multiple, up_to);
        }
    } else if (len == MAX_MULTIPLES) {
        for (int i = 0; i < MAX_MULTIPLES; i++) {
            subset[0] = multiples[combinations[i][0]];
            subset[1] = multiples[combinations[i][1]];
            common_multiple = lcm(subset, SUBSET_SIZE);
            if (common_multiple) {
                sum -= get_mult_sum(common_multiple, up_to);
            }
        }
        common_multiple = lcm(multiples, len);
        if (common_multiple) {
            sum += get_mult_sum(common_multiple, up_to);
        }
    }
    return sum;
}
