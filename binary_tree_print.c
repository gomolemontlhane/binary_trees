#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 *binary_tree_print - Prints a binary tree
 *@tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	printf("       ");
	printf(".-------(%03d)-------.\n", tree->n);
	if (tree->left != NULL || tree->right != NULL)
	{
		printf("  .--(%03d)--.         .--(%03d)--.\n",
			(tree->left ? tree->left->n : 0),
			(tree->right ? tree->right->n : 0));
		printf("(%03d)     (%03d)     (%03d)     (%03d)\n",
			(tree->left && tree->left->left ? tree->left->left->n : 0),
			(tree->left && tree->left->right ? tree->left->right->n : 0),
			(tree->right && tree->right->left ? tree->right->left->n : 0),
			(tree->right && tree->right->right ? tree->right->right->n : 0));
	}
}
