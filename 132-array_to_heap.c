#include "binary_trees.h"

/**
 * array_to_bst - Function that builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: Root node of created Binary Search Tree, NULL otherwise
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root_node = NULL;
	unsigned int i;

	for (i = 0; i < size; i++)
		bst_insert(&root_node, array[i]);

	return (root_node);
}
