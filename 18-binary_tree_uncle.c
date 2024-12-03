#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a given node in a binary tree.
 * @node: Pointer to the node whose uncle is to be found.
 *
 * Return: Pointer to the uncle node, or NULL if there is no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if the node, its parent, or grandparent is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	/* If the parent is the left child of the grandparent, the uncle is the right child */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* If the parent is the right child of the grandparent, the uncle is the left child */
	return (node->parent->parent->left);
}
