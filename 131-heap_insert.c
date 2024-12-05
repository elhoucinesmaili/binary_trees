#include "binary_trees.h"

/**
 * insert_to_max_heap - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
heap_t *insert_to_max_heap(heap_t **root, int value)
{
    heap_t *current, *new_node, *swap_node;
    int total_nodes, remaining_nodes, temp, level, mask;

    if (!root)
        return (NULL);
    if (!(*root))
        return (*root = binary_tree_node(NULL, value));

    current = *root;
    total_nodes = calculate_tree_size(current);
    remaining_nodes = total_nodes;

    for (level = 0, mask = 1; remaining_nodes >= mask; mask <<= 1, level++)
        remaining_nodes -= mask;

    for (mask = 1 << (level - 1); mask > 1; mask >>= 1)
        current = (remaining_nodes & mask) ? current->right : current->left;

    new_node = binary_tree_node(current, value);
    if (remaining_nodes & 1)
        current->right = new_node;
    else
        current->left = new_node;

    swap_node = new_node;
    while (swap_node->parent && (swap_node->n > swap_node->parent->n))
    {
        temp = swap_node->n;
        swap_node->n = swap_node->parent->n;
        swap_node->parent->n = temp;
        new_node = new_node->parent;
    }

    return (new_node);
}

/**
 * calculate_tree_size - Calculates the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree, or 0 if the tree is NULL.
 */
size_t calculate_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (calculate_tree_size(tree->left) + calculate_tree_size(tree->right) + 1);
}
