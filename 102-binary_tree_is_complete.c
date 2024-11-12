#include "binary_trees.h"

/**
 * tree_size - Helper function to measure the size of a binary tree
 * @tree: Is a pointer to the root node of the tree to measure the size
 * @size: Is a pointer to the size value
*/

void tree_size(const binary_tree_t *tree, int *size)
{
	if (tree == NULL)
		return;

	tree_size(tree->left, size);
	tree_size(tree->right, size);
	*size = *size + 1;
}

/**
 * tree_is_complete - Helper function to check if a binary tree is complete
 * @tree: Pointer to the current node in the tree
 * @index: Index of the current node
 * @count: Total number of nodes in the tree
 * @is_complete: Is a pointer to the checking value
 * Return: 1 if the tree is complete, 0 otherwise
 */

void tree_is_complete(const binary_tree_t *tree, int index,
								int count, int *is_complete)
{
	if (tree == NULL)
		return;

	if (index >= count)
		*is_complete = 0;

	tree_is_complete(tree->left, 2 * index + 1, count, is_complete);

	tree_is_complete(tree->right, 2 * index + 2, count, is_complete);

}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Is a pointer to the root node of the tree to check
 * Return: 1 if the tree is complete otherwise it returns 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size = 0;
	int is_complete = 1;

	if (tree == NULL)
		return (0);

	tree_size(tree, &size);
	tree_is_complete(tree, 0, size, &is_complete);
	return (is_complete);
}

