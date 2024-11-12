#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sorted_array_to_avl_helper - Helper function
 * to build an AVL tree from an array
 *
 * @array: Is a pointer to the first element of the array to be converted
 * @right: Is the end point of the array
 * @left: Is the start point of the array
 * @root: Is a pointer to the root of the AVL tree
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure
*/

avl_t *sorted_array_to_avl_helper(int *array, int left, int right, avl_t *root)
{
	int middle;
	avl_t *new_node = NULL;

	if (left <= right)
	{
		middle = (left + right) / 2;
		new_node = binary_tree_node(NULL, array[middle]);
		if (new_node == NULL)
			return (NULL);
		if (root == NULL)
			root = new_node;
		else if (new_node->n < root->n)
			root->left = new_node;
		else if (new_node->n > root->n)
			root->right = new_node;

		new_node->parent = root;
		sorted_array_to_avl_helper(array, left, middle - 1, new_node);
		sorted_array_to_avl_helper(array, middle + 1, right, new_node);
	}

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Is a pointer to the first element of the array to be converted
 * @size: Is the number of element in the array
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	root = sorted_array_to_avl_helper(array, 0, size - 1, root);
	return (root);
}
