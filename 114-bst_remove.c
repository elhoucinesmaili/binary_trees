#include "binary_trees.h"

/**
 * successor - Finds the in-order successor of a node, which is
 *             the minimum node in the right subtree.
 * @node: The node to find the successor for
 * 
 * Return: The minimum value in the right subtree of the node
 */
int successor(bst_t *node)
{
    if (node == NULL)
        return (0);

    /* Traverse the leftmost node in the right subtree */
    while (node->left != NULL)
        node = node->left;

    return (node->n);
}

/**
 * two_children - Handles the case where a node has two children by finding
 *                the in-order successor in the right subtree and replacing
 *                the current node value with the successor value.
 * @root: The node with two children
 * 
 * Return: The successor value that replaces the current node value
 */
int two_children(bst_t *root)
{
    int successor_value;

    successor_value = successor(root->right);
    root->n = successor_value;

    return (successor_value);
}

/**
 * remove_type - Removes a node based on its children count.
 *               If the node has no children, it is freed.
 *               If the node has one child, it is replaced by the child.
 *               If the node has two children, the successor value is used.
 * @root: The node to remove
 * 
 * Return: 0 if no children, or successor value if the node has two children
 */
int remove_type(bst_t *root)
{
    if (!root->left && !root->right)  /* No children */
    {
        if (root->parent->right == root)
            root->parent->right = NULL;
        else
            root->parent->left = NULL;
        free(root);
        return (0);
    }
    else if ((root->left && !root->right) || (!root->left && root->right))  /* One child */
    {
        bst_t *child = root->left ? root->left : root->right;

        if (root->parent->right == root)
            root->parent->right = child;
        else
            root->parent->left = child;

        child->parent = root->parent;
        free(root);
        return (0);
    }
    else  /* Two children */
    {
        return (two_children(root));
    }
}

/**
 * bst_remove - Removes a node with a specific value from a Binary Search Tree
 * @root: The root of the BST
 * @value: The value to remove
 * 
 * Return: The modified tree with the node removed
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return (NULL);

    /* Traverse to find the node to remove */
    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else  /* Node found */
    {
        int type = remove_type(root);
        if (type != 0)
            root->right = bst_remove(root->right, type);
    }

    return (root);
}

