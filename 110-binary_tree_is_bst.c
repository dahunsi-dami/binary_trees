#include "binary_trees.h"
#include <stdio.h>

/**
 * validate_left - Validates the left side of a tree to chec if it
 * is a valid Binary Search Tree
 *
 * @tree: Is a pointer to the root node of the tree to check
 * @is_bst: Is the checking value
 * @root_value: Is the value of the root node
 * Return: 1 if the tree is a Binary Search Tree otherwise it returns 0
*/

int validate_left(const binary_tree_t *tree, int *is_bst, int root_value)
{
	if (tree == NULL || *is_bst == 0)
		return (*is_bst);

	validate_left(tree->left, is_bst, root_value);
	validate_left(tree->right, is_bst, root_value);

	if (tree->n >= root_value)
		*is_bst = 0;

	return (*is_bst);
}

/**
 * validate_right - Validates the right side of a tree to chec if it
 * is a valid Binary Search Tree
 *
 * @tree: Is a pointer to the root node of the tree to check
 * @is_bst: Is the checking value
 * @root_value: Is the value of the root node
 * Return: 1 if the tree is a Binary Search Tree otherwise it returns 0
*/

int validate_right(const binary_tree_t *tree, int *is_bst, int root_value)
{
	if (tree == NULL || *is_bst == 0)
		return (*is_bst);

	validate_right(tree->left, is_bst, root_value);
	validate_right(tree->right, is_bst, root_value);

	if (tree->n <= root_value)
		*is_bst = 0;
	return (*is_bst);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Is a pointer to the root node of the tree to check
 * Return: 1 if the tree is a Binary Search Tree otherwise it returns 0
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int is_bst = 1;

	if (tree == NULL)
		return (0);

	validate_left(tree->left, &is_bst, tree->n);
	validate_right(tree->right, &is_bst, tree->n);
	return (is_bst);
}
