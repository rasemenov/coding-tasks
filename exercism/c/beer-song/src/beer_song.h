#ifndef BEER_SONG_H
#define BEER_SONG_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1024)
#endif

void verse(char *buffer, unsigned int verse_number);
void sing(char *buffer, unsigned int starting_verse_number,
          unsigned int ending_verse_number);

#endif
