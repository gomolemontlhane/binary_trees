#ifndef BINARY_TREES_H
#define BINARY_TREES_H
#include <stddef.h>

/*Basic Binary Tree Structure */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/*Function Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/*Function to print binary tree (for visualization purposes) */
void binary_tree_print(const binary_tree_t *);


#endif /*BINARY_TREES_H */
