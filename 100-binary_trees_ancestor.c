#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 * 
 * Return: pointer to the lowest common ancestor node, or NULL if no common ancestor exists.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_ancestor = (binary_tree_t *)first;
	binary_tree_t *second_ancestor = (binary_tree_t *)second;

	/* Traverse up from first node and store its ancestors */
	while (first_ancestor)
	{
		second_ancestor = (binary_tree_t *)second;
		while (second_ancestor)
		{
			/* Check if the ancestors are the same */
			if (first_ancestor == second_ancestor)
			{
				return (first_ancestor);
			}
			second_ancestor = second_ancestor->parent;
		}
		first_ancestor = first_ancestor->parent;
	}

	/* If no common ancestor is found, return NULL */
	return (NULL);
}
