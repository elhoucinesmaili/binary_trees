#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Depth of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

/**
 * is_perfect_rec - Checks if a binary tree is perfect recursively.
 * @tree: Pointer to the node to check.
 * @depth: Depth of the current node.
 * @level: Level of the current node.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect_rec(const binary_tree_t *tree, size_t depth, size_t level)
{
	/* If the tree is NULL, it is not perfect */
	if (tree == NULL)
		return (1);

	/* If it is a leaf node, it should be at the same depth level */
	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	/* If one child is NULL and the other is not, the tree is not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Check the left and right subtrees */
	return (is_perfect_rec(tree->left, depth, level + 1) &&
		is_perfect_rec(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise, or 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	/* If the tree is NULL, it is not perfect */
	if (tree == NULL)
		return (0);

	/* Find the depth of the leftmost leaf */
	depth = binary_tree_depth(tree);

	/* Call the recursive function to check if the tree is perfect */
	return (is_perfect_rec(tree, depth, 0));
}
