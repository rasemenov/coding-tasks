#include <stdio.h>
#include <string.h>
#include "beer_song.h"


size_t G_buffer_size = BUFFER_SIZE;


void verse(char *buffer, unsigned int verse_number) {
    char *verse;
    size_t verse_sz = G_buffer_size;
    switch (verse_number) {
        case 1:
           verse = "1 bottle of beer on the wall, 1 bottle of beer.\n"
                   "Take it down and pass it around, no more bottles "
                   "of beer on the wall.\n",
           strncpy(buffer, verse, verse_sz);
           break;
        case 0:
           verse = "No more bottles of beer on the wall, no "
                   "more bottles of beer.\n"
                   "Go to the store and buy some more, 99 bottles of "
                   "beer on the wall.\n",
           strncpy(buffer, verse, verse_sz);
           break;
        default:
           snprintf(
                    buffer,
                    verse_sz,
                    "%u bottles of beer on the wall, %u bottles of beer.\n"
                    "Take one down and pass it around, %u %s "
                    "of beer on the wall.\n",
                    verse_number,
                    verse_number,
                    verse_number - 1,
                    ((verse_number -1) == 1) ? "bottle" : "bottles");
           break;
    }
    buffer[verse_sz - 1] = '\0';
}


void sing(char *buffer, unsigned int starting_verse_number, 
          unsigned int ending_verse_number) {
    G_buffer_size = BUFFER_SIZE;
    char *tmp_buf = buffer;
    size_t verse_len = 0;
    memset(tmp_buf, 0, (size_t)BUFFER_SIZE);
    do {
        verse(tmp_buf, starting_verse_number);
        verse_len = strlen(tmp_buf);
        G_buffer_size -= verse_len;
        if (G_buffer_size <= 0)
            return;
        tmp_buf = tmp_buf + verse_len;
        if (starting_verse_number != ending_verse_number) {
            *tmp_buf++ = '\n';
            G_buffer_size--;
        }
    } while (starting_verse_number-- != ending_verse_number);
}
