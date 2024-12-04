#include "binary_trees.h"

int validate_bst(const binary_tree_t *tree, int lower, int upper);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (validate_bst(tree, INT_MIN, INT_MAX));
}

/**
 * validate_bst - Recursively validates the BST properties
 * @tree: Pointer to the current node being checked
 * @lower: The lower bound for the current node's value
 * @upper: The upper bound for the current node's value
 *
 * Return: 1 if the subtree is a valid BST, 0 otherwise
 */
int validate_bst(const binary_tree_t *tree, int lower, int upper)
{
    if (!tree)
        return (1);

    /* Ensure the current node's value is within the valid range */
    if (tree->n <= lower || tree->n >= upper)
        return (0);

    /* Recursively validate left and right subtrees */
    return (validate_bst(tree->left, lower, tree->n) &&
            validate_bst(tree->right, tree->n, upper));
}
