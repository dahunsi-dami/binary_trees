#include "binary_trees.h"
/**
 * tree_sibling - finds sibling of a node.
 * @node: pointer to the node to find the sibling.
 * Return: NULL if node/parent/no sibling, else pointer to sibling.
 */
binary_tree_t *tree_sibling(binary_tree_t *node)
{
	binary_tree_t *ln, *rn;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	if (node->parent->right ==  node)
		return (node->parent->left);

	ln = tree_sibling(node->parent->left);

	if (ln != NULL)
		return (ln);

	rn = tree_sibling(node->parent->right);

	return (rn);
}
/**
 * binary_tree_uncle - finds uncle of a node.
 * @node: pointer to the node to find the uncle.
 * Return: NULL if node/no uncle, else pointer to sibling.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->parent == NULL)
		return (NULL);

	return (tree_sibling(node->parent));
}
