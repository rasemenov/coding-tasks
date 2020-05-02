#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "raindrops.h"


const struct drop_kind drops_list[] = {
    {3, "Pling"},
    {5, "Plang"},
    {7, "Plong"},
};


char *convert(char result[], int drops) {
    char *buffer = result;
    bool match_found = false;
    size_t cnt;
    unsigned int free_chars = BUFFER_LENGTH - 1;
    for (cnt = 0; cnt < ARRAY_LENGTH(drops_list); cnt++) {
        if (!(drops % drops_list[cnt].factor)) {
            if (free_chars < strlen(drops_list[cnt].sound)) {
                printf("Buffer overflow for %d\n", drops);
            }
            strcpy(buffer, drops_list[cnt].sound);
            match_found = true;
            while (*buffer) {
                buffer++;
                free_chars--;
            }
        }
    }
    if (!match_found) {
        sprintf(buffer, "%d", drops);
    }
    return result;
}
