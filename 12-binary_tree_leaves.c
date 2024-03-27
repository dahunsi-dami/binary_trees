#include "binary_trees.h"
/**
 * binary_tree_leaves - counts leaves in a binary tree.
 * @tree: pointer to the root node to count leaves.
 * Return: 0 if tree is NULL, else leaf count.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t ll, rl;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	ll = binary_tree_leaves(tree->left);
	rl = binary_tree_leaves(tree->right);

	return (ll + rl);
}
