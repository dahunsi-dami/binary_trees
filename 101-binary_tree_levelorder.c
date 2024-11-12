#include "binary_trees.h"
#include <stdio.h>

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
 * print_given_level - Helper function to print nodes at the given level
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @level: The level to be printed.
 * @func: Pointer to a function to call for each node.
 * The value of the node must be passed as a parameter to this function.
 */
void print_given_level(const binary_tree_t *tree, size_t level,
														void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_given_level(tree->left, level - 1, func);
		print_given_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * The value of the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int tree_height = 0;
	int level;

	if (tree == NULL || func == NULL)
		return;

	height(tree, 0, &tree_height);

	for (level = 1; level <= tree_height; level++)
		print_given_level(tree, level, func);
}
