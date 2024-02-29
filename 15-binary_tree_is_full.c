#include "binary_trees.h"

/**
 *binary_tree_is_full - Checks if a binary tree is full.
 *@tree: A pointer to the root node of the tree to check.
 *
 *Return: If the tree is NULL or not full - 0.
 *        Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*If both children are NULL, it's a leaf */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/*If both children are not NULL, check recursively */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/*If only one child is NULL, it's not full */
	return (0);
}
