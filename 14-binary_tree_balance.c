#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * to measure the balance factor
 * Return: If tree is NULL, return 0, else return balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lH, rH;

	if (tree == NULL)
		return (0);

	lH = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
	rH = tree->right ? 1 + binary_tree_balance(tree->right) : 0;

	return (lH - rH);
}
