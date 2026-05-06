#include <stdio.h>
#include <stdlib.h>

#include "tally.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: tally <file>\n");
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    long lines = tally_count_lines(fp);
    fclose(fp);

    if (lines < 0) {
        fprintf(stderr, "tally: internal error while counting\n");
        return EXIT_FAILURE;
    }

    printf("%ld\n", lines);
    return EXIT_SUCCESS;
}
