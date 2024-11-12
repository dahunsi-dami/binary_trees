#include "binary_trees.h"

/**
 * insert - Helper function that inserts a value in a Binary Search Tree
 * @tree: Is a double pointer to the root node of the BST to insert the value
 * @value: Is the value to store in the node to be inserted
 * @parent: Is a double pointer to the parent of the current node
 * Return: A pointer to the created node, or NULL on failure
 */

bst_t *insert(bst_t **tree, bst_t **parent, int value)
{
	bst_t *new_node;

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		if (parent)
			(*tree)->parent = *parent;

		return (new_node);
	}

	if (value < (*tree)->n)
		new_node = insert(&((*tree)->left), tree, value);
	else if (value > (*tree)->n)
		new_node = insert(&((*tree)->right), tree, value);
	else
		return (NULL);
	return (new_node);
}

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Is a double pointer to the root node of the BST to insert the value
 * @value: Is the value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	return (insert(tree, NULL, value));
}
