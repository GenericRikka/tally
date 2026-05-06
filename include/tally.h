#ifndef TALLY_H
#define TALLY_H

#include <stdio.h>

/**
 * Count the number of newline characters in the given file stream.
 *
 * @param fp  An open, readable FILE stream. Must not be NULL.
 * @return    Number of newlines on success, -1 on error.
 */
long tally_count_lines(FILE *fp);

#endif 
