#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * 
 * Return: The height of the tree, 0 if tree is NULL
 */
static size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Recursively find the height of the left and right subtrees */
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	/* The height is the maximum of the left and right subtrees, plus 1 for the current node */
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * 
 * Return: The balance factor of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Calculate the balance factor as the difference between the height of the left and right subtrees */
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
