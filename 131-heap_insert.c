#include "binary_trees.h"

/**
 * bst_insert - Function that inserts a value in a Binary Search Tree
 * @root: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the new node, or NULL if the value is already in the tree
 */
bst_t *bst_insert(bst_t **root, int value)
{
	bst_t *tree, *new_node;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;

	/* Traverse the tree to find the correct position for the new node */
	while (tree)
	{
		if (value < tree->n)
		{
			if (!tree->left)
			{
				new_node = binary_tree_node(tree, value);
				tree->left = new_node;
				return (new_node);
			}
			tree = tree->left;
		}
		else if (value > tree->n)
		{
			if (!tree->right)
			{
				new_node = binary_tree_node(tree, value);
				tree->right = new_node;
				return (new_node);
			}
			tree = tree->right;
		}
		else
			return (NULL);  /* Value already exists, no duplicates allowed */
	}

	return (NULL);
}
