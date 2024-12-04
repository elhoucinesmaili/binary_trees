#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: The value to insert into the BST
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node = NULL;

    if (tree == NULL)
        return (NULL);

    /* If the tree is empty, create the root node */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    /* Traverse the tree to find the correct position */
    if (value < (*tree)->n)
    {
        if ((*tree)->left != NULL)
            return (bst_insert(&((*tree)->left), value));

        new_node = binary_tree_node(*tree, value);
        if (new_node != NULL)
            (*tree)->left = new_node;
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right != NULL)
            return (bst_insert(&((*tree)->right), value));

        new_node = binary_tree_node(*tree, value);
        if (new_node != NULL)
            (*tree)->right = new_node;
    }

    /* Return NULL if value is already present */
    return (new_node);
}
