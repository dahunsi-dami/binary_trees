#include "binary_trees.h"
/**
 * tree_size - Helper function to measure the size of a binary tree
 * @tree: Is a pointer to the root node of the tree to measure the size
 * @size: Is a pointer to the size value
*/

void tree_size(const binary_tree_t *tree, int *size)
{
	if (tree == NULL)
		return;

	tree_size(tree->left, size);
	tree_size(tree->right, size);
	*size = *size + 1;
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Is a double pointer to the root node of the Heap to insert the value
 * @value: Is the value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swap;
	int size = 0, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	tree_size(tree, &size);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	swap = new_node;
	for (; swap->parent && (swap->n > swap->parent->n); swap = swap->parent)
	{
		tmp = swap->n;
		swap->n = swap->parent->n;
		swap->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}

