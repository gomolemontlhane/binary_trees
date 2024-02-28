#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/*Basic Binary Tree Structure */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
}

binary_tree_t;

/*Function Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree); // Declaration for binary_tree_print

#endif /*BINARY_TREES_H */
