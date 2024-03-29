#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to return
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;

	if (pivot->left != NULL)
		pivot->left->parent = tree;

	tree->right = pivot->left;
	pivot->left = tree;
	pivot->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
		{
			tree->parent->left = pivot;
		}
		else
		{
			tree->parent->right = pivot;
		}
	}

	tree->parent = pivot;

	return (pivot);
}
