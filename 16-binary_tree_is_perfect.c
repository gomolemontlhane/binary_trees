#include "binary_trees.h"

/**
 *binary_tree_height - Measures the height of a binary tree.
 *@tree: A pointer to the root node of the tree to measure the height.
 *
 *Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}

	return (0);
}

/**
 *binary_tree_is_perfect - Checks if a binary tree is perfect.
 *@tree: A pointer to the root node of the tree to check.
 *
 *Return: If tree is NULL, your function must return 0,
 *        else return 1 if perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right))
			return (1);
	}

	return (0);
}
