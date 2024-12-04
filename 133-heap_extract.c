#include "binary_trees.h"
#include "0-binary_tree_node.c"

void in_order(bst_t *tree, bst_t **node, size_t height);
void balance_bst(bst_t *root);
size_t bst_height(const bst_t *tree);

/**
 * bst_extract - Function that extracts the root node of a Binary Search Tree
 * @root: Double pointer to the root of the BST
 * Return: Value, 0 otherwise
 */
int bst_extract(bst_t **root)
{
	int value;
	bst_t *bst, *new_node;

	if (!root || !*root)
		return (0);

	bst = *root;
	value = bst->n;
	if (!bst->left && !bst->right)
	{
		*root = NULL;
		free(bst);
		return (value);
	}

	in_order(bst, &new_node, bst_height(bst));

	bst->n = new_node->n;
	if (new_node->parent->right)
		new_node->parent->right = NULL;
	else
		new_node->parent->left = NULL;

	free(new_node);
	balance_bst(bst);
	*root = bst;
	return (value);
}

/**
 * in_order - Function that visits a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @node: The last node in in-order traversal
 * @height: The tree height
 *
 * Return: None
 */
void in_order(bst_t *tree, bst_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;

	height--;

	in_order(tree->left, node, height);
	in_order(tree->right, node, height);
}

/**
 * balance_bst - Function that balances the Binary Search Tree
 * @root: Pointer to binary search tree
 * Return: None
 */
void balance_bst(bst_t *root)
{
	bst_t *tmp_l, *tmp_r;
	int value;

	if (!root)
		return;

	tmp_l = root;

	while (1)
	{
		if (!tmp_l->left)
			break;

		if (!tmp_l->right)
			tmp_r = tmp_l->left;
		else
		{
			if (tmp_l->left->n > tmp_l->right->n)
				tmp_r = tmp_l->left;
			else
				tmp_r = tmp_l->right;
		}
		if (tmp_l->n > tmp_r->n)
			break;

		value = tmp_l->n;
		tmp_l->n = tmp_r->n;
		tmp_r->n = value;
		tmp_l = tmp_r;
	}
}

/**
 * bst_height - Function that measures the height of a binary search tree
 * @tree: Pointer to root node of BST to measure height
 * Return: Height, 0 otherwise
 */
size_t bst_height(const bst_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + bst_height(tree->left);

	if (tree->right)
		r_height = 1 + bst_height(tree->right);

	if (l_height > r_height)
		return (l_height);

	return (r_height);
}
