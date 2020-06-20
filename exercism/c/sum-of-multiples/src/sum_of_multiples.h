#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stddef.h>

int next_comb(unsigned int comb[], int k, int n);

unsigned int sum_of_multiples(const unsigned int *multiples,
                              size_t len, unsigned int up_to);

#endif
