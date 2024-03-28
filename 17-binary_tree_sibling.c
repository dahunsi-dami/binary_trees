#include "binary_trees.h"
/**
 * binary_tree_sibling - finds sibling of a node.
 * @node: pointer to the node to find the sibling.
 * Return: NULL if node/parent/no sibling, else pointer to sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *ln, *rn;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	if (node->parent->right ==  node)
		return (node->parent->left);

	ln = binary_tree_sibling(node->parent->left);

	if (ln != NULL)
		return (ln);

	rn = binary_tree_sibling(node->parent->right);

	return (rn);
}
