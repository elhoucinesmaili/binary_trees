#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: Pointer to the root of the modified tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return (NULL);

    /* Search for the node to be removed */
    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        /* Found the node to remove */
        root = remove_node(root);
    }

    return (root);
}

/**
 * remove_node - Helper function to remove a node from the tree
 * @root: The node to be removed
 *
 * Return: Pointer to the new root after removal
 */
bst_t *remove_node(bst_t *root)
{
    if (!root->left && !root->right)  /* No children */
    {
        free(root);
        return (NULL);
    }
    else if (root->left && !root->right)  /* Only left child */
    {
        bst_t *temp = root->left;
        free(root);
        return (temp);
    }
    else if (!root->left && root->right)  /* Only right child */
    {
        bst_t *temp = root->right;
        free(root);
        return (temp);
    }
    else  /* Two children */
    {
        int successor_value = find_successor(root->right);
        root->n = successor_value;
        root->right = bst_remove(root->right, successor_value);
    }

    return (root);
}

/**
 * find_successor - Finds the in-order successor of a node
 * @node: The node from which to find the successor
 *
 * Return: The value of the in-order successor
 */
int find_successor(bst_t *node)
{
    bst_t *current = node;

    /* Go to the leftmost node of the right subtree */
    while (current && current->left)
        current = current->left;

    return (current ? current->n : 0);  /* Return the successor value */
}

