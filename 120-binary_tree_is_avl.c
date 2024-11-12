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
 * height - Helper function to get the height of a node
 * @tree: Is a pointer to the root node of the tree to measure the height
 * @h: Is a pointer to the height value
 * @max_height: Is a pointer to max height value
*/
void height(const binary_tree_t *tree, int h, int *max_height)
{
	if (tree == NULL)
		return;

	h = h + 1;

	height(tree->left, h, max_height);
	height(tree->right, h, max_height);

	if (h > *max_height)
		*max_height = h;

	h = h - 1;
}


/**
 * tree_is_avl - Helper function to check if a binary tree is a valid AVL Tree
 * @tree: Is a pointer to the root node of the tree to check
 * Return: 1 it it's a avl tree otherwise it returns 0
*/

int tree_is_avl(const binary_tree_t *tree)
{
	int is_bst = 1;
	int balance_factor = 0;
	int left_height = 0;
	int right_height = 0;
	int left_is_avl = 1;
	int right_is_avl = 1;

	if (tree == NULL)
		return (1);

	height(tree->left, 0, &left_height);
	height(tree->right, 0, &right_height);

	balance_factor = left_height - right_height;
	validate_left(tree->left, &is_bst, tree->n);
	validate_right(tree->right, &is_bst, tree->n);

	left_is_avl = tree_is_avl(tree->left);
	right_is_avl = tree_is_avl(tree->right);

	if (!is_bst || balance_factor > 1 || balance_factor < -1
			|| !left_is_avl || !right_is_avl)
	{
		return (0);
	}
	else
		return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Is a pointer to the root node of the tree to check
 * Return: 1 it it's a avl tree otherwise it returns 0
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_is_avl(tree));
}
