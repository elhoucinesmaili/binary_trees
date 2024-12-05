#include "binary_trees.h"
#include <stdlib.h>

/**
 * calculate_height - Calculates the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if the tree is NULL.
 */
size_t calculate_height(const heap_t *tree)
{
    if (!tree)
        return (0);

    size_t left_height = calculate_height(tree->left);
    size_t right_height = calculate_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * calculate_size - Calculates the number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The size of the tree, or 0 if the tree is NULL.
 */
size_t calculate_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + calculate_size(tree->left) + calculate_size(tree->right));
}

/**
 * preorder_traverse - Performs pre-order traversal to find a specific node.
 * @tree: Pointer to the root node of the tree.
 * @target_node: Address of the pointer to store the found node.
 * @level: The target depth level.
 */
void preorder_traverse(heap_t *tree, heap_t **target_node, size_t level)
{
    if (!tree)
        return;

    if (!level)
    {
        *target_node = tree;
        return;
    }

    preorder_traverse(tree->left, target_node, level - 1);
    preorder_traverse(tree->right, target_node, level - 1);
}

/**
 * restore_heap - Restores the Max Binary Heap property.
 * @root: Pointer to the root of the heap.
 */
void restore_heap(heap_t *root)
{
    int temp;
    heap_t *max_child;

    if (!root)
        return;

    while (root->left)
    {
        if (!root->right || root->left->n > root->right->n)
            max_child = root->left;
        else
            max_child = root->right;

        if (root->n >= max_child->n)
            break;

        temp = root->n;
        root->n = max_child->n;
        max_child->n = temp;

        root = max_child;
    }
}

/**
 * extract_root - Extracts the root node from a Max Binary Heap.
 * @root: Double pointer to the root of the heap.
 *
 * Return: The value of the extracted root node.
 */
int extract_root(heap_t **root)
{
    int root_value;
    heap_t *last_node, *heap_root;

    if (!root || !*root)
        return (0);

    heap_root = *root;
    root_value = heap_root->n;

    if (!heap_root->left && !heap_root->right)
    {
        free(heap_root);
        *root = NULL;
        return (root_value);
    }

    preorder_traverse(heap_root, &last_node, calculate_height(heap_root) - 1);

    heap_root->n = last_node->n;

    if (last_node->parent->right == last_node)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);

    restore_heap(heap_root);
    *root = heap_root;

    return (root_value);
}
