#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    const binary_tree_t **queue;
    size_t head = 0, tail = 0;
    int encountered_null = 0;

    if (!tree)
        return (0);

    /* Allocate memory for the queue */
    queue = malloc(sizeof(*queue) * 1024); /* Assume max 1024 nodes for simplicity */
    if (!queue)
        return (0);

    queue[tail++] = tree;

    while (head < tail)
    {
        const binary_tree_t *node = queue[head++];

        if (node)
        {
            if (encountered_null)
            {
                /* If a NULL was previously encountered, the tree is not complete */
                free(queue);
                return (0);
            }
            /* Enqueue children */
            queue[tail++] = node->left;
            queue[tail++] = node->right;
        }
        else
        {
            /* Mark that a NULL node has been encountered */
            encountered_null = 1;
        }
    }

    free(queue);
    return (1);
}
