#include "binary_trees.h"
#include <stdlib.h>

/**
 * _tree_size - Helper function to measure the size of a binary tree
 * @tree: Is a pointer to the root node of the tree to measure the size
 * @size: Is a pointer to the size value
*/

void _tree_size(binary_tree_t *tree, size_t *size)
{
	if (tree == NULL)
		return;

	_tree_size(tree->left, size);
	_tree_size(tree->right, size);
	*size = *size + 1;
}
/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *arr = NULL;
	size_t s = 0;

	if (!heap || !size)
		return (NULL);

	_tree_size(heap, &s);
	*size = s;
	arr = malloc(sizeof(int) * (*size));

	if (!arr)
		return (NULL);

	for (i = 0; heap; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}
