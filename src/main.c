#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tally.h"

int main(int argc, char *argv[]) {
    const char *Usage =
        "Usage: tally <filename> = count lines\nUsage: tally -w "
        "<filename> = count words\nUsage: tally -c <filename> "
        "= count characters\n";

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "%s", Usage);
        return EXIT_FAILURE;
    }
    char *filename;
    if (argc == 3) {

        if (strcmp(argv[1], "-w") != 0 && strcmp(argv[1], "-c") != 0) {
            fprintf(stderr, "%s", Usage);
            return EXIT_FAILURE;
        }

        filename = argv[2];
    } else {

        if (argc == 2 && strcmp(argv[1], "-w") == 0) {
            fprintf(stderr, "%s", Usage);
            return EXIT_FAILURE;
        }

        else if (argc == 2 && strcmp(argv[1], "-c") == 0) {
            fprintf(stderr, "%s", Usage);
            return EXIT_FAILURE;
        }

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
    }

    else if (strcmp(argv[1], "-c") == 0) {
        long characters = tally_count_characters(fp);
        fclose(fp);

        if (characters < 0) {
            fprintf(stderr, "tally: internal error while counting\n");
            return EXIT_FAILURE;
        }

        printf("%ld\n", characters);
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
