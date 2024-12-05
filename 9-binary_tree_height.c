#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
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
            l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
            r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
        }
        return ((l > r) ? l : r);
    }
}

/**
 * binary_tree_balance - Function that measures the balance factor of a binary tree
 * @tree: tree to check balance
 * Return: the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
    int l_height = 0;
    int r_height = 0;

    if (tree == NULL)
    {
        return (0);
    }

    l_height = (int)binary_tree_height(tree->left);
    r_height = (int)binary_tree_height(tree->right);

    return (l_height - r_height);
}
