#include "binary_trees.h"

/**
 *
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lH, rH;

	if (tree == NULL)
		return (0);

	lH = binary_tree_height(tree->left);
	rH = binary_tree_height(tree->right);

	if (lH == rH)
	{
		if (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right))
			return (1);
	}
	return (0);
}


int binary_tree_height(const binary_tree_t *tree)
{
	int lH, rH;

	if (tree == NULL)
		return (0);

	lH = binary_tree_height(tree->left);
	rH = binary_tree_height(tree->right);

	return ((lH > rH ? lH : rH) + 1);
}
