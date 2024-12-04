#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root after rotation, or NULL on failure
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (!tree || !tree->right)
        return (NULL);

    /* Update the root to the right child */
    new_root = tree->right;
    tree->right = new_root->left;

    /* Update parent references */
    if (new_root->left)
        new_root->left->parent = tree;

    new_root->left = tree;

    /* Update parent of new root */
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return (new_root);
}
