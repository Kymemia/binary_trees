#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: NULL if no common ancestor was found, else return common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *a = (binary_tree_t *)first;
	binary_tree_t *b = (binary_tree_t *)second;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return (a);

	while (a != b)
	{
		a = (a ? a->parent : (binary_tree_t *)second);
		b = (b ? b->parent : (binary_tree_t *)first);
	}

	return (a);
}
