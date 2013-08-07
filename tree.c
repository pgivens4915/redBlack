// The red black tree implementation
# include "tree.h"
# include <stdio.h> // for DEBUG

// A testing function
void test(){
  printf("Linking Works\n");
  return;
}

// A function for printing out trees
void printTree(node* node, int depth){
 // If the left child exists, print its tree
 if (node->left){
   printTree(node->left, depth + 1);
 }
 // Print the root in order
 printBranch(node, depth);
 // If the right child exists, print its tree
 if (node->right){
   printTree(node->right, depth + 1);
 }
}

// A function for printing out branches
void printBranch(node* node, int depth){
  // Declarations
  int i = 0;

  // Prints out a long branch
  for(i = 0; i < depth; i++){
    printf("-");
  }
  // After the branch is printed, display the info
  printf("<%c%i\n", node->color, node->value);
}
