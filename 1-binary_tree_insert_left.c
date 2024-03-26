#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts node as left child of another node.
 * @parent: pointer to the parent node of the node to create.
 * @value: value to put in the new node.
 * Return: pointer to the new node or NULL on failure/parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newlnode;

	newlnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newlnode == NULL || parent == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newlnode->left = parent->left;
		parent->left = newlnode;
		newlnode->parent = parent;
		newlnode->left->parent = newlnode;
	}
	else
	{
		newlnode->left = NULL;
		parent->left = newlnode;
		newlnode->parent = parent;
	}
	
	newlnode->n = value;
	newlnode->right = NULL;

	return (newlnode);
}
