#include "binary_trees.h"
/**
 * binary_tree_depth - measures depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth.
 * Return: 0 if tree is NULL, else node depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t c;

	c = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		c++;
		tree = tree->parent;
	}

	if (tree->parent == NULL)
		c += 0;

	return (c);
}
