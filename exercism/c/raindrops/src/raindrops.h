#ifndef RAINDROPS_H
#define RAINDROPS_H


#define BUFFER_LENGTH 16
#define ARRAY_LENGTH(array) (sizeof((array)) / sizeof((array[0])))

struct drop_kind {
    int factor;
    const char *sound;
};

char *convert(char result[], int drops);

#endif
