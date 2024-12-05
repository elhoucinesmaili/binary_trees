#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *current, *new_node, *swap;
    int tmp, height, mask, position, total_nodes;

    if (!root)
        return (NULL);

    if (!(*root))
        return (*root = binary_tree_node(NULL, value));

    current = *root;
    total_nodes = binary_tree_size(current);

    for (height = 0, position = 1; total_nodes >= position; position *= 2, height++)
        total_nodes -= position;

    for (mask = 1 << (height - 1); mask > 1; mask >>= 1)
        current = (total_nodes & mask) ? current->right : current->left;

    new_node = binary_tree_node(current, value);
    (total_nodes & 1) ? (current->right = new_node) : (current->left = new_node);

    swap = new_node;
    while (swap->parent && swap->n > swap->parent->n)
    {
        tmp = swap->n;
        swap->n = swap->parent->n;
        swap->parent->n = tmp;
        swap = swap->parent;
    }

    return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
