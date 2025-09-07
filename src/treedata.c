#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treedata.h"

/**
 * Compares two string pointers using strcmp.
 * Returns:
 *   < 0 if a < b
 *   = 0 if a == b
 *   > 0 if a > b
 */
int compareStrings(void *a, void *b) {
    if (!a || !b) return 0;
    return strcmp((char *)a, (char *)b);
}

/**
 * Frees a string pointer.
 */
void destroyString(void *data) {
    free(data);
}

/**
 * Returns a deep copy of the string (using strdup).
 */
void *copyString(void *data) {
    if (!data) return NULL;
    return strdup((char *)data);
}

/**
 * Prints a string to stdout followed by a newline.
 */
void printString(void *data) {
    if (data) {
        printf("%s\n", (char *)data);
    }
}