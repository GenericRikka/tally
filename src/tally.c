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
