#include "binary_trees.h"

/**
 * check_if_inorder - traverse binary tree using in-order
 * @tree: pointer to the root node of tree to check
 * @prev: pointer to previous node
 * Return: valid binary search tree
 */

int check_if_inorder(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);
	if (!check_if_inorder(tree->left, prev))
		return (0);
	if (tree->n <= *prev)
		return (0);

	*prev = tree->n;

	return (check_if_inorder(tree->right, prev));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree, 0 if not + if tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (tree == NULL)
		return (0);

	return (check_if_inorder(tree, &prev));
}
