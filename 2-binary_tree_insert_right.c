#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts node as right child of another node.
 * @parent: pointer to the parent node of the node to create.
 * @value: value to put in the new node.
 * Return: pointer to the new node or NULL on failure/parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newlnode;

	if (parent == NULL)
		return (NULL);

	newlnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newlnode == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		newlnode->right = parent->right;
		parent->right = newlnode;
		newlnode->parent = parent;
		newlnode->right->parent = newlnode;
	}
	else
	{
		newlnode->right = NULL;
		parent->right = newlnode;
		newlnode->parent = parent;
	}

	newlnode->n = value;
	newlnode->left = NULL;

	return (newlnode);
}
