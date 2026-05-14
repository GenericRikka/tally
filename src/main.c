#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tally.h"

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: tally <file>\n");
        return EXIT_FAILURE;
    }

    char *filename;
    if (argc == 3) {
        filename = argv[2];
    } else {
        filename = argv[1];
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror(filename);
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "-w") == 0) {
        long words = tally_count_words(fp);
        fclose(fp);

        if (words < 0) {
            fprintf(stderr, "tally: internal error while counting\n");
            return EXIT_FAILURE;
        }

        printf("%ld\n", words);
        return EXIT_SUCCESS;
    } else {
        long lines = tally_count_lines(fp);
        fclose(fp);

        if (lines < 0) {
            fprintf(stderr, "tally: internal error while counting\n");
            return EXIT_FAILURE;
        }

        printf("%ld\n", lines);
        return EXIT_SUCCESS;
    }
}
