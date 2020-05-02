#include "bob.h"

#include <ctype.h>
#include <stdbool.h>
#include <string.h>


static void process_msg(char *string, int str_len, int *last_char,
                        bool *is_upper, bool *is_empty) {
    int i;
    char letter;
    bool found_letter = false;
    *is_upper = true;
    for (i = 0; i < str_len; i++) {
        letter = string[i];
        if (!isspace(letter)) {
            *last_char = i;
            *is_empty = false;
        }
        if (isalpha(letter)) {
            found_letter = true;
            if (!isupper(letter)) {
                *is_upper = false;
            }
        }
    }
    *is_upper = found_letter ? *is_upper : false;
    return;
}


char *hey_bob(char *greeting) {
    int str_len, last_char = 0;
    bool is_yell = false, is_empty=true;
    char *return_str = NULL;
    char *fine_str = "Fine. Be that way!";
    str_len = strlen(greeting);
    if (!greeting) {
        return "";
    }
    if (!str_len) {
        return fine_str;
    }
    process_msg(greeting, str_len, &last_char, &is_yell, &is_empty);
    if (is_empty) {
        return fine_str;
    }
    switch (greeting[last_char]) {
    case '?':
        return_str = is_yell ? "Calm down, I know what I'm doing!" : "Sure.";
        break;
    default:
        return_str = is_yell ? "Whoa, chill out!" : "Whatever.";
        break;
    }
    return return_str;
}
