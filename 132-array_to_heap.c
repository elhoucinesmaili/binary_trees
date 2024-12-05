#include "binary_trees.h"

/**
 * build_max_heap - Constructs a Max Binary Heap tree from an array.
 * @array: Pointer to the first element of the input array.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure.
 */
heap_t *build_max_heap(int *array, size_t size)
{
    heap_t *root = NULL;

    if (!array || size == 0)
        return (NULL);

    for (size_t i = 0; i < size; i++)
        heap_insert(&root, array[i]);

    return (root);
}
