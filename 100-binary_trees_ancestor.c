#include "binary_trees.h"
#include <stdio.h>

/**
 * check_ancestor - Checks if a node is an ancestor for another node
 * @parent: Is a pointer to the node to check if it's an ancestor
 * @child: Is a pointer to the node to check
 * if the parent node is an ancestor for it
 *
 * @is_ancestor: A pointer to the checking value which set to 1 if the parent
 * is an ancestor for the child node and 0 if it's not
*/

void check_ancestor(const binary_tree_t *parent,
	const binary_tree_t *child, int *is_ancestor)
{
	if (parent == NULL || *is_ancestor)
		return;

	check_ancestor(parent->left, child, is_ancestor);
	check_ancestor(parent->right, child, is_ancestor);

	if (parent == child)
	{
		*is_ancestor = 1;
		return;
	}
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Is a pointer to the first node
 * @second: Is a pointer to the second node
 * Return: A pointer to the lowest common ancestor node of the two given nodes
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	int is_ancestor = 0;
	const binary_tree_t *temp = first;

	if (first == NULL || second == NULL)
		return (NULL);

	while (temp)
	{
		check_ancestor(temp, second, &is_ancestor);
		if (is_ancestor)
			return ((binary_tree_t *) temp);

		temp = temp->parent;
	}

	return (NULL);
}
