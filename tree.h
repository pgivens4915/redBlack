#include <stdio.h>
// The red black tree header
typedef struct node node;

// A single node of a red black tree
struct node{
  node* parent;
  node* left;
  node* right;
  int value;
  char color;
};

void test(); // DEBUG function

// A function to print out the tree
// Arguments
// node  - The root of there tree we are printing
// depth - The depth of the root we are printing at
void printTree(node* node, int depth);

// A function that prints out a - representing the depth of the branch
// Arguments
// node  - The node we are printing out
// depth - The depth of the tree / the length of the branch
void printBranch(node* node, int depth);

// A function that adds a node
// Arguments
// parent - The parent of the current node
// node   - The current node of intrest
// value  - The value you want to add
node* addNumber(node* parent, node* node, int value);
