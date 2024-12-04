#include "binary_trees.h"

/**
 * insert - Helper function that does node value insertion in an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @parent: Pointer to the parent node of the tree (used for new node insertion)
 * @new_node: Pointer to the new node being created
 * @new_val: The value to insert into the AVL tree
 *
 * Return: Pointer to the new root node or NULL if insertion failed
 */
avl_t *insert(avl_t **tree, avl_t *parent, avl_t **new_node, int new_val)
{
    int bal_val;

    /* If tree is empty, create the new node */
    if (*tree == NULL)
    {
        *new_node = binary_tree_node(parent, new_val);
        return (*new_node);
    }

    /* Insert into left or right subtree based on the value */
    if ((*tree)->n > new_val)
    {
        (*tree)->left = insert(&(*tree)->left, *tree, new_node, new_val);
        if ((*tree)->left == NULL)
            return (NULL);
    }
    else if ((*tree)->n < new_val)
    {
        (*tree)->right = insert(&(*tree)->right, *tree, new_node, new_val);
        if ((*tree)->right == NULL)
            return (NULL);
    }
    else
    {
        /* Return the existing node if value is already present */
        return (*tree);
    }

    /* Balance the tree */
    bal_val = binary_tree_balance(*tree);
    if (bal_val > 1 && (*tree)->left->n > new_val)
        *tree = binary_tree_rotate_right(*tree);  /* Left-Left Case */

    else if (bal_val > 1 && (*tree)->left->n < new_val)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);  /* Left-Right Case */
        *tree = binary_tree_rotate_right(*tree);
    }
    else if (bal_val < -1 && (*tree)->right->n < new_val)
        *tree = binary_tree_rotate_left(*tree);  /* Right-Right Case */

    else if (bal_val < -1 && (*tree)->right->n > new_val)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);  /* Right-Left Case */
        *tree = binary_tree_rotate_left(*tree);
    }

    return (*tree);
}

/**
 * avl_insert - Function that inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to insert into the tree
 *
 * Return: Pointer to the new node if insertion is successful, NULL otherwise
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL;

    /* If the tree is empty, create the root node */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    /* Call the insert function to insert the value */
    insert(tree, *tree, &new_node, value);
    return (new_node);
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
 * @value: Value to store in the new node
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

