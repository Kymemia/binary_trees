#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;

	if (pivot->right != NULL)
		pivot->right->parent = tree;

	tree->left = pivot->right;
	pivot->right = tree;
	pivot->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->right == tree)
		{
			tree->parent->right = pivot;
		}
		else
		{
			tree->parent->left = pivot;
		}
	}
	tree->parent = pivot;

	return (pivot);
}
