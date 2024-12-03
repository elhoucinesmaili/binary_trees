#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void binary_tree_level(const binary_tree_t *tree, size_t i, void (*func)(int));

/**
 * binary_tree_levelorder - Function that visits a binary tree with level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * Return: None
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t level, i;

    if (tree == NULL || func == NULL)
        return;

    level = binary_tree_height(tree);

    for (i = 1; i <= level; i++)
        binary_tree_level(tree, i, func);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height of
 * Return: Height of the tree, 0 if otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left, right;

    if (tree == NULL)
        return (0);

    left = binary_tree_height(tree->left);
    right = binary_tree_height(tree->right);

    if (left >= right)
        return (1 + left);

    return (1 + right);
}

/**
 * binary_tree_level - Function that performs a function on a specific level of the binary tree
 * @tree: Pointer to the root of the tree
 * @i: The level of the tree to perform the function on
 * @func: The function
 * Return: None
 */
void binary_tree_level(const binary_tree_t *tree, size_t i, void (*func)(int))
{
    if (tree == NULL)
        return;

    if (i == 1)
        func(tree->n);
    else if (i > 1)
    {
        binary_tree_level(tree->left, i - 1, func);
        binary_tree_level(tree->right, i - 1, func);
    }
}
