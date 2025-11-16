# Binary Trees

## Overview

This repository contains comprehensive C implementations of binary tree data structures and algorithms. The project provides foundational understanding of tree traversals, manipulations, and various tree property validations. These implementations are crucial for understanding advanced data structures and algorithms used in computer science.

## Project Description

Binary Trees is a complete implementation of binary tree operations in C, covering fundamental concepts from basic node creation and insertion through advanced tree properties like balance checking and perfect binary tree validation. Each task builds upon previous implementations to create a solid foundation in tree-based algorithms.

## Task Summary

This project consists of 19 progressive tasks:

| Task | Title | Concepts | Difficulty |
|------|-------|----------|------------|
| 0 | New Node | Dynamic memory allocation, struct creation | Beginner |
| 1 | Insert Left | Pointer manipulation, tree insertion | Beginner |
| 2 | Insert Right | Recursive insertion, tree structure | Beginner |
| 3 | Delete | Memory deallocation, tree traversal | Beginner |
| 4 | Leaf Check | Tree traversal, node properties | Intermediate |
| 5 | Is Root | Node identification | Intermediate |
| 6 | Pre-order | Tree traversal, recursion | Intermediate |
| 7 | In-order | Tree traversal, recursion | Intermediate |
| 8 | Post-order | Tree traversal, recursion | Intermediate |
| 9 | Height | Tree height calculation, recursion | Intermediate |
| 10 | Depth | Node depth calculation | Intermediate |
| 11 | Size | Tree size calculation | Intermediate |
| 12 | Leaves | Leaf node counting | Intermediate |
| 13 | Nodes | Full node counting | Intermediate |
| 14 | Balance Factor | Tree balance analysis | Advanced |
| 15 | Full Binary Tree | Complete tree validation | Advanced |
| 16 | Perfect Binary Tree | Perfect tree validation | Advanced |
| 17 | Sibling | Sibling node identification | Advanced |
| 18 | Uncle | Uncle node identification | Advanced |

## Learning Outcomes

Upon completing this project, you will:

- ✓ Understand binary tree data structure and implementation
- ✓ Implement fundamental tree operations (insertion, deletion)
- ✓ Master tree traversal algorithms (pre-order, in-order, post-order)
- ✓ Calculate tree properties (height, depth, size)
- ✓ Validate tree characteristics (full, perfect, balanced)
- ✓ Navigate tree relationships (parent, child, sibling, uncle)
- ✓ Work with dynamic memory allocation in C
- ✓ Use recursion effectively for tree algorithms
- ✓ Implement callbacks and function pointers
- ✓ Analyze algorithm complexity for tree operations

## Key Concepts

### Tree Fundamentals
- **Binary Tree**: A tree where each node has at most two children (left and right)
- **Root**: The topmost node of the tree
- **Leaf**: A node with no children
- **Internal Node**: A node with at least one child
- **Height**: Maximum distance from node to leaf
- **Depth**: Distance from root to node
- **Level**: Set of nodes at the same depth

### Tree Properties
- **Full Binary Tree**: Every node has either 0 or 2 children
- **Perfect Binary Tree**: All internal nodes have 2 children and all leaves are at same level
- **Balanced Binary Tree**: Heights of left and right subtrees differ by at most 1
- **Complete Binary Tree**: All levels filled except possibly the last, which is filled left to right

### Tree Traversals
- **Pre-order**: Node → Left → Right (used for copying tree)
- **In-order**: Left → Node → Right (gives sorted order for BST)
- **Post-order**: Left → Right → Node (used for deletion)
- **Level-order**: Visit nodes level by level

### Memory Management
- Dynamic allocation with malloc
- Proper deallocation to avoid memory leaks
- Recursion stack considerations

## Technical Stack

- **Language**: C (C99 standard)
- **Compiler**: GCC with -Wall -Werror -Wextra flags
- **Tools**: Make, GDB for debugging
- **Memory Management**: malloc, free, calloc

## File Structure

```
binary_trees/
├── binary_trees.h          # Main header file with struct definitions
├── 0-binary_tree_node.c     # Task implementations
├── 1-binary_tree_insert_left.c
├── 2-binary_tree_insert_right.c
├── 3-binary_tree_delete.c
├── ...
├─┠ 0-main.c                # Test files for each task
├─┠ 1-main.c
├─┠ 2-main.c
├─┠ ...
├─┠ 0-node                  # Compiled executables
├─┠ 1-left
├─┠ 2-right
├─┠ ...
├── binary_tree_print.c     # Utility for printing trees
└── README.md               # Project documentation
```

## Core Data Structure

```c
/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer value stored in node
 * @parent: Pointer to the parent node
 * @left: Pointer to left child
 * @right: Pointer to right child
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;
```

## Basic Operations Examples

### Creating a New Node

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);
    
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return (new_node);
}
```

### Pre-order Traversal

```c
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree != NULL)
    {
        func(tree->n);
        binary_tree_preorder(tree->left, func);
        binary_tree_preorder(tree->right, func);
    }
}
```

### Calculating Height

```c
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);
    
    return (1 + (left_height > right_height ? left_height : right_height));
}
```

## Compilation

```bash
# Compile a single task
gcc -Wall -Werror -Wextra -pedantic *.c -o executable_name

# Example: Compile task 0
gcc -Wall -Werror -Wextra -pedantic 0-binary_tree_node.c 0-main.c binary_tree_print.c -o 0-node

# Run the executable
./0-node
```

## Compilation Flags Explanation

- `-Wall`: Enable all common compiler warnings
- `-Werror`: Treat all warnings as errors
- `-Wextra`: Enable additional warning messages
- `-pedantic`: Enforce strict ANSI C compliance

## Testing

Each task includes a main.c file that tests the implementation:

```bash
# Test task 0
cd .
gcc -Wall -Werror -Wextra -pedantic 0-binary_tree_node.c 0-main.c binary_tree_print.c -o 0-node
./0-node

# Test task 1
gcc -Wall -Werror -Wextra -pedantic 1-binary_tree_insert_left.c 1-main.c binary_tree_print.c -o 1-left
./1-left
```

## Algorithm Complexity Analysis

| Operation | Average | Worst Case | Notes |
|-----------|---------|------------|-------|
| Search | O(n) | O(n) | Unbalanced tree |
| Insert | O(log n) | O(n) | Depends on balance |
| Delete | O(log n) | O(n) | Depends on balance |
| Traversal | O(n) | O(n) | Visits all nodes |
| Height | O(n) | O(n) | Must visit all nodes |

## Common Pitfalls & Solutions

### Memory Leaks
**Problem**: Forgetting to free allocated memory
**Solution**: Always pair malloc with free; use valgrind to detect leaks

```bash
valgrind --leak-check=full ./executable_name
```

### Segmentation Faults
**Problem**: Accessing NULL pointers or uninitialized memory
**Solution**: Always check for NULL before dereferencing; initialize pointers

### Incorrect Recursion
**Problem**: Stack overflow or infinite loops
**Solution**: Ensure base case is correct and handles NULL nodes

## Debugging Tips

1. Use `gdb` for step-by-step execution
2. Add print statements in recursive functions
3. Use `valgrind` to detect memory issues
4. Visualize tree structure using binary_tree_print function
5. Test with edge cases (empty tree, single node, unbalanced tree)

## Resources & References

### C Programming
- [C99 Standard Reference](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)
- [GCC Compiler Options](https://gcc.gnu.org/onlinedocs/gcc/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)

### Data Structures
- [Binary Trees - Wikipedia](https://en.wikipedia.org/wiki/Binary_tree)
- [Tree Traversal Algorithms](https://en.wikipedia.org/wiki/Tree_traversal)
- [Balanced Trees](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)

### Debugging Tools
- [GDB Debugger](https://sourceware.org/gdb/documentation/)
- [Valgrind Memory Tool](https://valgrind.org/info/tools.html)

## Next Steps

After completing this project:

1. Implement **Binary Search Trees (BST)** for ordered operations
2. Learn **AVL Trees** for self-balancing properties
3. Study **Red-Black Trees** for optimal balance
4. Explore **B-Trees** for database applications
5. Implement **Heaps** for priority queue operations

## Contributing

This is an educational repository. Improvements and corrections are welcome:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## Compilation Standards

- **Language Standard**: C99
- **Compilation Flags**: `-Wall -Werror -Wextra -pedantic`
- **Platform**: Linux (tested on Ubuntu 20.04+)
- **Compiler**: GCC 9.0+

## Status & Difficulty

- **Repository Status**: Active Learning Project
- **Overall Difficulty**: Intermediate
- **Est. Time to Complete**: 2-4 weeks
- **Prerequisite Knowledge**: C programming basics, pointers, dynamic memory
- **Recommended Pace**: 1-2 tasks per day

## License

This educational repository is provided as-is for learning purposes.

---

**Last Updated**: 2025
**Total Tasks**: 19
**Language**: C (C99)
**Memory Safe**: Yes (malloc/free properly managed)
