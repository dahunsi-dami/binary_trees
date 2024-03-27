#include "binary_trees.h"
/**
 * binary_tree_postorder - goes thru binary tree w/ postorder traversal.
 * @tree: pointer to root node of tree to traverse.
 * @func: pointer to function to call for each node.
 * Return: nothing as function returns void.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
