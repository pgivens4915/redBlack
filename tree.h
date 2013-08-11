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

// A function that starts balancing the red black tree
// It will pass on to the next case if not applicable
// Arguments
// current - The current node being worked on
void balance1(node* current);

// A function the takes care of the second case in adding to a red black tree
// Case : The current node's parent is black
// Arguments
// current - The current node being balanced
void balance2(node* current);

// A function that takes care of the third case in adding to a red black tree
// Case : Both parent and uncle are red
// Arguments
// current - The current node being balanced
void balance3(node* current);

// A function that takes care of the fourth case in adding to a red black tree
// Case : Parent is red but uncle is black, and the sidedness 
//        of the parent and current are different
// Arguments
// current - The current node being balanced
void balance4(node* current);

// A function that left rotates a tree
// NOTE : Current must have a right child
// Arguments
// current - The node to rotate around
void leftRotate(node* current);

// A function that right rotates a tree
// NOTE : Current must have a left child
// Arguments
// current - The node to rotate around
void rightRotate(node* current);

// A function that returns the the uncle node
// NOTE : Returns NULL if nothing found
// Arguments
// current - The current node being balanced
node* uncle(node* current);

// A function that returns the grandparent node
// NOTE : Returns NULL if nothing found
// Arguments
// current - The current node being balanced
node* grandparent(node* current);
