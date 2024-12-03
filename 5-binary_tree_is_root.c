#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is the root of a binary tree
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a root, 0 otherwise or if node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    if (node == NULL)
        return (0);

    /* A root node has no parent */
    if (node->parent == NULL)
        return (1);

    return (0);
}
