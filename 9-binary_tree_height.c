#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL, else return appropriate measures
 */
size_t max(size_t x, size_t y)
{
		return (x > y ? x : y);
}
size_t binary_tree_height(const binary_tree_t *tree)
{	
	if (tree == NULL)
		return (0);
	
	return (max(binary_tree_height(tree->left), binary_tree_height(tree->right)) + 1);
}
