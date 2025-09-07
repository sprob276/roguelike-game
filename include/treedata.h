#ifndef TREEDATA_H
#define TREEDATA_H

typedef int   (*CompareFunc)(void *, void *);
typedef void  (*DestroyFunc)(void *);
typedef void *(*CopyFunc)(void *);
typedef void  (*PrintFunc)(void *);

// --- Example Data Functions for Strings ---

int compareStrings(void *a, void *b);
void destroyString(void *data);
void *copyString(void *data);
void printString(void *data);

#endif