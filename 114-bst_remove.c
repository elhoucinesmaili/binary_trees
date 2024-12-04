#include "binary_trees.h"

/**
 * bst_min - find the minimum value node in a BST
 * @node: node to start searching from
 * Return: pointer to the node with the minimum value
 */
bst_t *bst_min(bst_t *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

/**
 * bst_remove - removes a node from the BST
 * @root: pointer to the root of the BST
 * @value: value to remove
 * Return: pointer to the new root of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (!root)
        return NULL;

    if (value < root->n)
    {
        root->left = bst_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = bst_remove(root->right, value);
    }
    else
    {
        if (!root->left)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            bst_t *min_node = bst_min(root->right);
            root->n = min_node->n;
            root->right = bst_remove(root->right, min_node->n);
        }
    }

    return root;
}
