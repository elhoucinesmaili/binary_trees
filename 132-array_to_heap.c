#include "binary_trees.h"

/**
 * build_heap_from_array - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the array's first element
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure
 */
heap_t *build_heap_from_array(int *array, size_t size)
{
    heap_t *root = NULL;
    size_t index;

    if (!array || size == 0)
        return (NULL);

    for (index = 0; index < size; index++)
    {
        if (!heap_insert(&root, array[index]))
        {
            /* Clean up and return NULL in case of failure */
            /* Add cleanup logic if necessary */
            return (NULL);
        }
    }

    return (root);
}
