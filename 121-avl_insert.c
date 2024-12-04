#include "binary_trees.h"

/**
 * avl_insert - Function to insert a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 * 
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return (NULL);
    
    // Insert the value into the tree as we would in a normal BST
    if (!*tree)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        if (!(*tree)->left)
            (*tree)->left = avl_insert(&(*tree)->left, value);
        else
            avl_insert(&(*tree)->left, value);
    }
    else if (value > (*tree)->n)
    {
        if (!(*tree)->right)
            (*tree)->right = avl_insert(&(*tree)->right, value);
        else
            avl_insert(&(*tree)->right, value);
    }
    else
    {
        return (NULL);  // Duplicate values are not allowed in AVL tree
    }

    // Balance the tree and return the node
    *tree = balance_tree(*tree);
    return (*tree);
}

/**
 * balance_tree - Balances the tree by checking the balance factor and performing rotations
 * @tree: Pointer to the node to balance
 * 
 * Return: Pointer to the balanced node
 */
avl_t *balance_tree(avl_t *tree)
{
    int balance = binary_tree_balance(tree);

    // Left heavy tree
    if (balance > 1)
    {
        if (binary_tree_balance(tree->left) >= 0)
            tree = binary_tree_rotate_right(tree); // Single Right Rotation
        else
        {
            tree->left = binary_tree_rotate_left(tree->left); // Left-Right Rotation
            tree = binary_tree_rotate_right(tree);
        }
    }
    // Right heavy tree
    else if (balance < -1)
    {
        if (binary_tree_balance(tree->right) <= 0)
            tree = binary_tree_rotate_left(tree); // Single Left Rotation
        else
        {
            tree->right = binary_tree_rotate_right(tree->right); // Right-Left Rotation
            tree = binary_tree_rotate_left(tree);
        }
    }

    return (tree);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the node to measure balance
 * 
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    
    return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the node to measure height
 * 
 * Return: Height of the tree, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree node
 * @tree: Pointer to the root node of the subtree to rotate
 * 
 * Return: Pointer to the new root node of the rotated subtree
 */
avl_t *binary_tree_rotate_left(avl_t *tree)
{
    avl_t *new_root = tree->right;

    tree->right = new_root->left;
    new_root->left = tree;

    return (new_root);
}

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree node
 * @tree: Pointer to the root node of the subtree to rotate
 * 
 * Return: Pointer to the new root node of the rotated subtree
 */
avl_t *binary_tree_rotate_right(avl_t *tree)
{
    avl_t *new_root = tree->left;

    tree->left = new_root->right;
    new_root->right = tree;

    return (new_root);
}

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 * 
 * Return: Pointer to the newly created node
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
    avl_t *node = malloc(sizeof(avl_t));

    if (!node)
        return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
