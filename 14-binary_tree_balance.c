#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * 
 * Return: The height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	/* Return 0 if the tree is NULL */
	if (tree == NULL)
		return (0);

	/* Calculate the height of the left and right subtrees */
	l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	/* Return the maximum height between left and right subtrees */
	return ((l > r) ? l : r);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * 
 * Return: The balance factor of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0, balance = 0;

	/* If the tree is not NULL, calculate the balance factor */
	if (tree)
	{
		left = (int)binary_tree_height(tree->left);
		right = (int)binary_tree_height(tree->right);

		/* The balance factor is the difference in heights of left and right subtrees */
		balance = left - right;
	}

	return (balance);
}
