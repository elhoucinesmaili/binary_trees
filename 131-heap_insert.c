#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: Root node of the created Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL;
    size_t index;

    if (!array || size == 0)
        return (NULL);

    for (index = 0; index < size; index++)
    {
        if (!heap_insert(&root, array[index]))
        {
            /* Free the entire tree if insertion fails */
            binary_tree_free(root);
            return (NULL);
        }
    }

    return (root);
}

/**
 * binary_tree_free - Frees a binary tree
 * @tree: Pointer to the root of the tree to free
 */
void binary_tree_free(heap_t *tree)
{
    if (!tree)
        return;

    binary_tree_free(tree->left);
    binary_tree_free(tree->right);
    free(tree);
}
