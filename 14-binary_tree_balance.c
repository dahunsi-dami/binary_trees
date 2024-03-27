#include "binary_trees.h"
/**
 * tree_height - measures the height of a binary tree.
 * @tree: pointer to root node of tree to measure the height.
 * Return: 0 if tree is NULL, else tree height.
 */
int tree_height(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (0);

	/* if (tree->left == NULL && tree->right == NULL) */
	/*	return (0); */

	l = tree_height(tree->left);
	r = tree_height(tree->right);

	if (l > r)
		return (l + 1);
	else
		return (r + 1);
}
/**
 * binary_tree_balance - measures balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: 0 if tree is NULL, else balance factor of tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lb, rb;

	if (tree == NULL)
		return (0);

	lb = tree_height(tree->left);
	rb = tree_height(tree->right);

	return (lb - rb);

}
