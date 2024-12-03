#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 if not, or 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* If the tree is NULL, it is not full */
	if (tree == NULL)
		return (0);

	/* If the node is a leaf (no children), it is full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If both left and right children are not NULL, check recursively */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If one of the children is NULL, the tree is not full */
	return (0);
}
