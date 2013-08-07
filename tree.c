// The red black tree implementation
# include "tree.h"
# include <stdio.h> 
# include <stdlib.h>
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

node* addNumber(node* parent, node* current, int value){
  // Base case, if our node is empty add a new node
  // and return a pointer to the node added
  if (!current){
    // Create a new node
    current = malloc(sizeof(node));
    current->parent = parent;
    current->left   = NULL;
    current->right  = NULL;
    current->value  = value;
    current->color  = 'r';
    return current;
  }
  // If the value is equal to what is stored, return the node
  else if (current->value == value){
    printf("Duplicate\n");
    return current;
  }
  // If the value is less than, add it to the left
  else if (current->value < value){
    current->left = addNumber(current, current->left, value);
    return current;
  }
  // Else it is greater than
  else {
    current->right = addNumber(current, current->right, value);
    return current;
  }
}
