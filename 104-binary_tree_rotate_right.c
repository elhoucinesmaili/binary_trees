#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after rotation, or NULL if tree is NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (!tree || !tree->left)
        return (NULL);

    /* Move the left child up as the new root */
    new_root = tree->left;
    tree->left = new_root->right;

    /* Update parent pointers for the subtree being moved */
    if (new_root->right)
        new_root->right->parent = tree;

    /* Update parent pointers for the rotated nodes */
    new_root->right = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return (new_root);
}
