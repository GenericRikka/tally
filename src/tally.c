#include "tally.h"

long tally_count_lines(FILE *fp) {
    if (!fp)
        return -1;

    long count = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n')
            count++;
    }

    return count;
}

long tally_count_words(FILE *fp) {
    if (!fp)
        return -1;

    long count = 0;
    int c;
    int in_word = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            in_word = 0;
        } else {
            if (in_word == 0) {
                count++;
                in_word = 1;
            }
        }
    }

    return count;
}
