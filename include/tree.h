#ifndef TREE_H
#define TREE_H

#include "treedata.h"

// Opaque type
typedef struct TreeNode TreeNode;

typedef struct Tree {
    TreeNode *root;
    CompareFunc compare;
    DestroyFunc destroy;
    CopyFunc copy;
} Tree;

// --- Core Tree Operations ---

/**
 * Creates a new, empty tree with the specified function pointers.
 */
Tree *createTree(CompareFunc compare, DestroyFunc destroy, CopyFunc copy);

/**
 * Frees all memory used by the tree.
 */
void destroyTree(Tree *tree);

/**
 * Inserts a new item into the tree.
 * Returns 0 on success, non-zero on failure.
 */
int insertNode(Tree *tree, void *data);

/**
 * Finds a node containing the given key.
 * Returns a pointer to the TreeNode, or NULL if not found.
 */
TreeNode *findNode(Tree *tree, void *key);

/**
 * Prints the tree in-order using the provided print function.
 */
void printInOrder(Tree *tree, PrintFunc printData);

// --- Tree Accessors ---

/**
 * Returns the root node of the tree.
 */
TreeNode *getRoot(Tree *tree);

/**
 * Returns the data stored in a node.
 */
void *getNodeData(TreeNode *node);

/**
 * Returns the left child of a node.
 */
TreeNode *getLeftChild(TreeNode *node);

/**
 * Returns the right child of a node.
 */
TreeNode *getRightChild(TreeNode *node);

/**
 * Returns the height of a node.
 */
int getNodeHeight(TreeNode *node);

#endif