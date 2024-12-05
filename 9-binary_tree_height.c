#include "binary_trees.h"

/**
 * measure_tree_height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The height of the tree, or 0 if the tree is NULL
 */
size_t measure_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = 0, right_height = 0;

    if (tree->left)
        left_height = 1 + measure_tree_height(tree->left);

    if (tree->right)
        right_height = 1 + measure_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height);
}
