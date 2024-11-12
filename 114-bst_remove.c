#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_minimum - Finds the minimum node in a tree
 * @root: Is a pointer to the first node of the tree
 * Return: The node that contains the minimum value
*/

bst_t *find_minimum(bst_t *root)
{
	if (root == NULL)
	return (NULL);

	if (root->left == NULL)
		return (root);

	return (find_minimum(root->left));
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where you will remove a node
 * @value: Is the value to remove from the tree
 * Return: A pointer to the new root node of the tree
 * after removing the desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor = NULL, *temp = NULL;

	if (root == NULL)
		return (NULL);
	if (value == root->n)
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		if (root->left == NULL)
		{
			temp = root->right;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else
		{
			successor = find_minimum(root->right);
			root->n = successor->n;
			root->right = bst_remove(root->right, successor->n);
		}
	}
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else
		root->right = bst_remove(root->right, value);
	return (root);
}
