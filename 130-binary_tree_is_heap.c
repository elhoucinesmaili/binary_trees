#include "binary_trees.h"

/**
 * heap_insert - Function that inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the new node, or NULL if failed
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	/* If the heap is empty, create the root node */
	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Insert the value in the tree as a complete binary tree */
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	/* Find the correct position to insert (complete binary tree) */
	if (insert_as_complete_tree(*root, new_node) == 0)
	{
		free(new_node);
		return (NULL);
	}

	/* Perform "heapify-up" to maintain max-heap property */
	parent = new_node->parent;
	while (parent && new_node->n > parent->n)
	{
		/* Swap values with the parent to maintain heap property */
		swap(new_node, parent);
		new_node = parent;
		parent = new_node->parent;
	}

	return (new_node);
}

/**
 * insert_as_complete_tree - Helper function to insert a node in a complete tree
 * @root: Root of the heap
 * @new_node: New node to insert
 * Return: 1 if inserted successfully, 0 otherwise
 */
int insert_as_complete_tree(heap_t *root, heap_t *new_node)
{
	heap_t *queue[1024];  /* Array to store nodes at each level */
	int front = 0, rear = 0;

	if (!root || !new_node)
		return (0);

	/* Enqueue root node */
	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *current = queue[front++];

		/* Check if the current node has a left child */
		if (!current->left)
		{
			current->left = new_node;
			new_node->parent = current;
			return (1);
		}
		else
		{
			queue[rear++] = current->left;
		}

		/* Check if the current node has a right child */
		if (!current->right)
		{
			current->right = new_node;
			new_node->parent = current;
			return (1);
		}
		else
		{
			queue[rear++] = current->right;
		}
	}

	return (0);  /* Failed to insert */
}

/**
 * swap - Helper function to swap the values of two nodes
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap(heap_t *node1, heap_t *node2)
{
	int tmp = node1->n;
	node1->n = node2->n;
	node2->n = tmp;
}
