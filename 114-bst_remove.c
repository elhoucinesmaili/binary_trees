#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a balanced tree
 * @tree: tree to go through
 * Return: the height
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
    size_t l = 0;
    size_t r = 0;

    if (tree == NULL)
    {
        return (0);
    }
    else
    {
        if (tree)
        {
            l = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
            r = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
        }
        return ((l > r) ? l : r);
    }
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int right = 0, left = 0, total = 0;

    if (tree)
    {
        left = ((int)binary_tree_height_b(tree->left));
        right = ((int)binary_tree_height_b(tree->right));
        total = left - right;
    }
    return (total);
}

/**
 * binary_tree_is_balanced - Checks if a binary tree is balanced
 * @tree: tree to check
 * Return: 1 if balanced, 0 if not
 */
int binary_tree_is_balanced(const binary_tree_t *tree)
{
    int balance = 0;

    if (tree == NULL)
    {
        return (0);
    }

    balance = binary_tree_balance(tree);

    if (balance >= -1 && balance <= 1)
    {
        return (1);
    }
    return (0);
}
