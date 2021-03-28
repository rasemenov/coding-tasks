#include "anagram.h"

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


static int calculate_score(int *score_array, const char *word) {
    memset(score_array, 0, NLETTERS * sizeof(int));
    int len = strlen(word), res = 0;
    for (int indx = 0; indx < len; indx++) {
        char letter = tolower(word[indx]);
        if (!isalpha(letter)) {
            res = 1;
            break;
        }
        int pos = letter - 'a';
        if (pos < 0 || pos > NLETTERS - 1) {
            res = 1;
            break;
        }
        score_array[pos]++;
    }
    return res;
}


static bool check_candidate(int *base_score, int *word_score) {
    bool res = true;
    for (int indx = 0; indx < NLETTERS; indx++) {
        if (base_score[indx] != word_score[indx]) {
            res = false;
            break;
        }
    }
    return res;
}


void find_anagrams(const char *subject,
                   struct candidates *candidates) {
    if (!subject || !candidates) {
        return;
    }
    int base_score[NLETTERS] = {0}, word_score[NLETTERS] = {0};
    if (calculate_score(base_score, subject)) {
        return;
    }
    for (int indx = 0, len = candidates->count; indx < len; indx++) {
        struct candidate *c = &candidates->candidate[indx];
        if (calculate_score(word_score, c->word)
            || !strcasecmp(subject, c->word)) {
            c->is_anagram = NOT_ANAGRAM;
            continue;
        }
        if (check_candidate(base_score, word_score)) {
            c->is_anagram = IS_ANAGRAM;
        } else {
            c->is_anagram = NOT_ANAGRAM;
        }
    }
}
