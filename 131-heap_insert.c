#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);

/**
 * heap_insert - Function that inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: New node, NULL otherwise
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swap;
	int tmp, level, bit, sub, leaves, size;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	swap = new_node;
	for (; swap->parent && (swap->n > swap->parent->n);
			swap = swap->parent)
	{
		tmp = swap->n;
		swap->n = swap->parent->n;
		swap->parent->n = tmp;
		new_node = new_node->parent;
	}
	return (new_node);
}

/**
 * binary_tree_size - Function that measures the size of a binary tree
 * @tree: The tree to measure the size of
 * Return: size of tree, 0 otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
