#include "binary_trees.h"

/**
 * find_sibling - function that finds the sibling of a node in a binary tree
 * @node: node to check for a sibling
 * Return: pointer to the sibling node, or NULL if none
 */
binary_tree_t *find_sibling(binary_tree_t *node)
{
    /* Check for invalid input or a root node without a sibling */
    if (node == NULL || node->parent == NULL)
    {
        return (NULL);
    }

    /* If the node is the left child, return the right sibling */
    if (node->parent->left == node)
    {
        return (node->parent->right);
    }

    /* If the node is the right child, return the left sibling */
    return (node->parent->left);
}
