#include "binary_trees.h"
#include <stdio.h>

/**
 * insert - Helper function that inserts a value in a Binary Search Tree
 * @tree: Is a double pointer to the root node of the BST to insert the value
 * @value: Is the value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */


bst_t *insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	if (value < (*tree)->n)
	{
		new_node = insert(&((*tree)->left), value);
		if ((*tree)->left)
			(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		new_node = insert(&((*tree)->right), value);

		if ((*tree)->right)
			(*tree)->right->parent = *tree;
	}
	else
		return (NULL);
	return (new_node);
}


/**
 * make_tree_avl - Turns a BST to AVL tree if it's not a AVL already
 * @tree: Is a double pointer to the root node of the BST tree
*/

void make_tree_avl(avl_t **tree)
{
	int balance_factor = 0;

	if (*tree == NULL)
		return;

	make_tree_avl(&(*tree)->right);
	make_tree_avl(&(*tree)->left);

	balance_factor = binary_tree_balance(*tree);

	if (balance_factor > 1)
	{
		if (binary_tree_balance((*tree)->left) < 0)
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}

	if (balance_factor < -1)
	{
		if (binary_tree_balance((*tree)->right) > 0)
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Is a double pointer to the root node of the AVL tree
 * for inserting the value
 *
 * @value: Is the value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
*/

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	new_node = insert(tree, value);

	make_tree_avl(tree);

	return (new_node);
}
