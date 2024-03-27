#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 0 if tree is NULL, else 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int lf, rf;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left) && (tree->right))
	{
		lf = binary_tree_is_full(tree->left);
		rf = binary_tree_is_full(tree->right);

		return (lf && rf);
	}

	return (0);
}
