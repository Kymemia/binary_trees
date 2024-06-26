#include "binary_trees.h"

/**
 * binary_tree_depth - easures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: 0 is tree is NULL, else accurate depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
	{
		return (1 + binary_tree_depth(tree->parent));
	}
	else
	{
		return (0);
	}
}
