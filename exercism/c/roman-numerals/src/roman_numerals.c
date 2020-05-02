#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_numerals.h"


struct conversion_map {
    unsigned int arabic;
    char *roman;
};


static const struct conversion_map numbers_map[] = {
    {1, "I"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"},
    {8, "VIII"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"},
    {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"}, {100, "C"},
    {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"},
    {900, "CM"}, {1000, "M"}
};


static int print_ntimes(char *buffer, int buf_sz,
                        const char* letter, unsigned int ntimes);


static int print_ntimes(char *buffer, int buf_sz,
                        const char* letter, unsigned int ntimes) {
    int written = 0, rc;
    unsigned int cnt;
    for (cnt = 0; cnt < ntimes; cnt++) {
        rc = snprintf(buffer, buf_sz, "%s", letter);
        if (rc < 0 || rc == sizeof(letter))
            return -1;
        buffer += rc;
        buf_sz -= rc;
        written += rc;
    }
    return written;
}


char *to_roman_numeral(unsigned int number) {
    int i, rc, buf_sz = BUFFER_SZ;
    char *res, *buf;
    unsigned int norder;
    if (!number || number > 3999)
        return NULL;
    res = buf = malloc(buf_sz);
    memset(res, 0, buf_sz);
    do {
        for (i = ARRAY_LENGTH(numbers_map) - 1; i >= 0; i--) {
            norder = number / numbers_map[i].arabic;
            if (number == numbers_map[i].arabic) {
                norder = 1;
                number = 0;
            }
            if (norder) {
                number %= numbers_map[i].arabic;
                rc = print_ntimes(buf, buf_sz, numbers_map[i].roman, norder);
                if (rc < 0) {
                    free(res);
                    return NULL;
                }
                buf += rc;
                buf_sz -= rc;
                break;
            }
        }
    } while (number);
    return res;
}
