#include "binary_trees.h"

/**
 * binary_tree_sibling - A function to find the sibling of a node in a binary tree
 * @node: A pointer to the node whose sibling is to be found
 * 
 * This function works by checking the parent node of the input node.
 * It returns the sibling node (the other child of the parent).
 * If no sibling exists (either the node or parent is NULL), it returns NULL.
 * 
 * Return: The pointer to the sibling node or NULL if there's no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    /* Check if the node or its parent is NULL */
    if (node == NULL || node->parent == NULL)
    {
        return (NULL);
    }

    /* If the node is the left child of its parent, return the right child */
    if (node->parent->left == node)
    {
        return (node->parent->right);
    }

    /* Otherwise, return the left child of the parent */
    return (node->parent->left);
}
