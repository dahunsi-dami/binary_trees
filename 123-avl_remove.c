#include "binary_trees.h"
#include <stdlib.h>

/**
 * rebalance_avl_tree - Turns a BST to AVL tree if it's not a AVL already
 * @tree: Is a double pointer to the root node of the BST tree
*/

void rebalance_avl_tree(avl_t **tree)
{
	int balance_factor = 0;

	if (*tree == NULL)
		return;

	rebalance_avl_tree(&(*tree)->right);
	rebalance_avl_tree(&(*tree)->left);

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
 * find_minimum - Finds the minimum node in a tree
 * @root: Is a pointer to the first node of the tree
 * Return: The node that contains the minimum value
*/

bst_t *find_minimum(bst_t *root)
{
	if (root == NULL)
	return (NULL);

	if (root->left == NULL)
		return (root);

	return (find_minimum(root->left));
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Isa pointer to the root node of the tree for removing a node
 * @value: Is the value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree
 * after removing the desired value, and after rebalancing
*/

avl_t *avl_remove(avl_t *root, int value)
{
	bst_t *successor = NULL, *temp = NULL;

	if (root == NULL)
		return (NULL);

	if (value == root->n)
	{
		if (root->right == NULL && root->left == NULL)
		{
			free(root);
			return (NULL);
		}
		if (root->right == NULL)
		{
			temp = root->left;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else
		{
			successor = find_minimum(root->right);
			root->n = successor->n;
			root->right = avl_remove(root->right, successor->n);
		}
	}
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);

	rebalance_avl_tree(&root);
	return (root);
}
