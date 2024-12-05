#include "binary_trees.h"

size_t calculate_tree_size(const binary_tree_t *tree);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to insert
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *current, *new_node, *swap_node;
    int temp, level, mask, remainder, leaf_count, tree_size;

    if (!root)
        return (NULL);

    if (!(*root))
        return (*root = binary_tree_node(NULL, value));

    current = *root;
    tree_size = calculate_tree_size(current);
    leaf_count = tree_size;

    /* Determine the level and leaf position */
    for (level = 0, remainder = 1; leaf_count >= remainder; remainder *= 2, level++)
        leaf_count -= remainder;

    /* Traverse to the parent of the insertion point */
    for (mask = 1 << (level - 1); mask > 1; mask >>= 1)
        current = (leaf_count & mask) ? current->right : current->left;

    /* Create the new node and attach it */
    new_node = binary_tree_node(current, value);
    if (leaf_count & 1)
        current->right = new_node;
    else
        current->left = new_node;

    /* Perform upward heapification */
    swap_node = new_node;
    while (swap_node->parent && swap_node->n > swap_node->parent->n)
    {
        temp = swap_node->n;
        swap_node->n = swap_node->parent->n;
        swap_node->parent->n = temp;
        new_node = swap_node->parent;
        swap_node = swap_node->parent;
    }

    return (new_node);
}

/**
 * calculate_tree_size - Computes the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The size of the tree (number of nodes), or 0 if tree is NULL
 */
size_t calculate_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (calculate_tree_size(tree->left) + calculate_tree_size(tree->right) + 1);
}
