#include "strrindex.h"

#include <stddef.h>

int strrindex(char src[], char pattern[]) {
    char *head_src = NULL;
    char *head_pattern = NULL;
    const char * const src_base = src;
    int indx = -1;
    while (*src) {
        head_src = src;
        head_pattern = pattern;
        while (*head_pattern && *head_pattern++ == *head_src++) {
            if (*head_pattern == '\0') {
                indx = src - src_base;
            }
        }
        src++;
    }
    return indx;
}
