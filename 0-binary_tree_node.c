#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree code
 * @parent: pointer to parent node of the node to create
 * @value: value to be stored inside the node
 * Return: NULL on failure,
 * else return a pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent != NULL)
	{
		if (value <= parent->n)
		{
			parent->left = new_node;
		}
		else
		{
			parent->right = new_node;
		}
	}

	return (new_node);
}
