#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 *        be passed as a parameter to this function.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Traverse the left subtree */
	binary_tree_postorder(tree->left, func);

	/* Traverse the right subtree */
	binary_tree_postorder(tree->right, func);

	/* Call the function on the current node */
	func(tree->n);
}
