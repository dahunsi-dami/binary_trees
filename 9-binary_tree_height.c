#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to root node of tree to measure the height.
 * Return: 0 if tree is NULL, else tree height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	if (l > r)
		return (l + 1);
	else
		return (r + 1);
}
