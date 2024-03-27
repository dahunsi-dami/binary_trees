#include "binary_trees.h"
/**
 * tree_size - measures size of a binary tree.
 * @tree: pointer to the root node to measure tree size.
 * Return: 0 if tree is NULL, else node size.
 */
int tree_size(const binary_tree_t *tree)
{
	int ls, rs;

	if (tree == NULL)
		return (0);

	ls = tree_size(tree->left);
	rs = tree_size(tree->right);

	return (ls + 1 + rs);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 0 if tree is NULL, else 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int length;

	if (tree == NULL)
		return (0);

	length = tree_size(tree);
	return (length & (length + 1)) == 0;
}
