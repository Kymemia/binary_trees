#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 0 if tree is NULL, else returns tally of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int left_kid;
	int right_kid;
	int tally;

	if (tree == NULL)
		return (0);

	left_kid = binary_tree_nodes(tree->left);
	right_kid = binary_tree_nodes(tree->right);
	tally = (tree->left != NULL || tree->right != NULL) ? 1 : 0;

	return (tally + left_kid + right_kid);
}
