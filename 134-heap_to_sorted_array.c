#include "binary_trees.h"

/**
 * calculate_tree_size - Calculates the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Total number of nodes, or 0 if the tree is NULL.
 */
size_t calculate_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + calculate_tree_size(tree->left) + calculate_tree_size(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the resulting array.
 *
 * Return: Pointer to an array sorted in descending order, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array = NULL;
    size_t index;

    if (!heap || !size)
        return (NULL);

    /* Calculate the size of the heap */
    *size = calculate_tree_size(heap);

    /* Allocate memory for the sorted array */
    array = malloc(sizeof(int) * (*size));
    if (!array)
        return (NULL);

    /* Extract elements from the heap into the array */
    for (index = 0; heap; index++)
        array[index] = heap_extract(&heap);

    return (array);
}
