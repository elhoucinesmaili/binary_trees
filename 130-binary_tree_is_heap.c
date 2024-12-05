#include "binary_trees.h"

int validate_heap(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, size_t index, size_t total_nodes);
size_t get_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (validate_heap(tree));
}

/**
 * validate_heap - Validates that a binary tree satisfies Max Binary Heap properties
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if valid Max Binary Heap, 0 otherwise
 */
int validate_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (1);

    if (!is_complete(tree, 0, get_tree_size(tree)))
        return (0);

    if (tree->left && tree->left->n > tree->n)
        return (0);

    if (tree->right && tree->right->n > tree->n)
        return (0);

    return (validate_heap(tree->left) && validate_heap(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Current index of the node
 * @total_nodes: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t total_nodes)
{
    if (!tree)
        return (1);

    if (index >= total_nodes)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, total_nodes) &&
            is_complete(tree->right, 2 * index + 2, total_nodes));
}

/**
 * get_tree_size - Calculates the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t get_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + get_tree_size(tree->left) + get_tree_size(tree->right));
}

