#include "binary_trees.h"
/**
 * predecessor - get the in-order predecessor (max node in the left subtree)
 * @node: tree to check
 * Return: the max value of this tree
 */
int predecessor(bst_t *node)
{
	int right = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		right = predecessor(node->right);
		if (right == 0)
		{
			return (node->n);
		}
		return (right);
	}
}

/**
 * two_children - function that gets the in-order predecessor using the max
 * value in the left subtree, and then replace the node value for
 * this predecessor
 * @root: node that has two children
 * Return: the value found
 */
int two_children(bst_t *root)
{
	int new_value = 0;

	new_value = predecessor(root->left);
	root->n = new_value;
	return (new_value);
}

/**
 * remove_type - function that removes a node depending on its children
 * @root: node to remove
 * Return: 0 if it has no children or another value if it has
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}

/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->left, type);
	}
	else
		return (NULL);
	return (root);
}
