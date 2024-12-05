#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_minimum - Finds the minimum value node in a binary tree
 * @node: Pointer to the root of the subtree
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *find_minimum(bst_t *node)
{
    if (!node)
        return (NULL);
    while (node->left)
        node = node->left;
    return (node);
}

/**
 * delete_node - Handles the removal of a node with a given value
 * @root: Pointer to the root of the subtree
 *
 * Return: Pointer to the root of the modified subtree
 */
bst_t *delete_node(bst_t *root)
{
    bst_t *replacement;

    if (!root->left && !root->right) /* No children */
    {
        free(root);
        return (NULL);
    }
    if (root->left && root->right) /* Two children */
    {
        replacement = find_minimum(root->right); /* In-order successor */
        root->n = replacement->n;
        root->right = bst_remove(root->right, replacement->n); /* Remove successor */
    }
    else /* One child */
    {
        replacement = root->left ? root->left : root->right;
        replacement->parent = root->parent;
        free(root);
        return (replacement);
    }
    return (root);
}

/**
 * bst_remove - Removes a node with a given value from a BST
 * @root: Pointer to the root of the tree
 * @value: Value of the node to be removed
 *
 * Return: Pointer to the new root of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (!root)
        return (NULL);

    if (value < root->n) /* Search in the left subtree */
        root->left = bst_remove(root->left, value);
    else if (value > root->n) /* Search in the right subtree */
        root->right = bst_remove(root->right, value);
    else /* Node with the value found */
        root = delete_node(root);

    return (root);
}
