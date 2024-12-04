#include "binary_trees.h"

/* Helper function prototypes */
int is_complete(const binary_tree_t *tree, size_t index, size_t total_nodes);
size_t count_nodes(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t total_nodes;

    if (!tree)
        return (0);

    /* Get the total number of nodes in the tree */
    total_nodes = count_nodes(tree);

    /* Check completeness by recursively validating node indices */
    return (is_complete(tree, 0, total_nodes));
}

/**
 * is_complete - Recursively checks if the binary tree is complete
 * @tree: Pointer to the current node
 * @index: Index of the current node
 * @total_nodes: Total number of nodes in the tree
 *
 * Return: 1 if the subtree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree,
