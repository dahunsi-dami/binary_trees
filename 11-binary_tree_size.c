#include "binary_trees.h"
/**
 * binary_tree_size - measures size of a binary tree.
 * @tree: pointer to the root node to measure tree size.
 * Return: 0 if tree is NULL, else node size.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t ls, rs;

	if (tree == NULL)
		return (0);

	ls = binary_tree_size(tree->left);
	rs = binary_tree_size(tree->right);

	return (ls + 1 + rs);
}
