#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: The height of the tree.
 */
int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    int left_height = height(tree->left);
    int right_height = height(tree->right);

    if (left_height == -1 || right_height == -1)
        return (-1);  /* Not balanced */

    if (abs(left_height - right_height) > 1)
        return (-1);  /* Not balanced */

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Check if the tree is a BST and the heights are balanced */
    if (binary_tree_is_bst(tree) && height(tree) != -1)
        return (1);

    return (0);
}

/**
 * binary_tree_is_bst - Helper function to check if a binary tree is a BST.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    return (bst_check(tree, INT_MIN, INT_MAX));
}

/**
 * bst_check - Recursively checks if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum allowed value for the node.
 * @max: Maximum allowed value for the node.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (bst_check(tree->left, min, tree->n) && bst_check(tree->right, tree->n, max));
}
