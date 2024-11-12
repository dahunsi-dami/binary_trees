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
 * @size: Total number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */

int tree_is_complete(const binary_tree_t *tree, int index, int size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (tree_is_complete(tree->left, 2 * index + 1, size)
	&& tree_is_complete(tree->right, 2 * index + 2, size));
}

/**
 * tree_is_max_heap - Helper function
 * to check if a binary tree is a valid Max Binary Heap
 *
 * @tree: Is a pointer to the root node of the sub tree to check
 * Return: 1 if tree is a valid Max Binary Heap, otherwise it returns 0
*/

int tree_is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (tree_is_max_heap(tree->left) && tree_is_max_heap(tree->right));
}


/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, otherwise it returns 0
*/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int size = 0;
	int is_max = 1;
	int is_complete = 0;

	if (tree == NULL)
		return (0);

	tree_size(tree, &size);
	is_complete = tree_is_complete(tree, 0, size);
	is_max = tree_is_max_heap(tree);

	return (is_max && is_complete);
}
