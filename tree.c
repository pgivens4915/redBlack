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
    if (current->parent && current->value < parent->value){
      parent->right = current;
    }
    else if (current->parent){
      parent->left = current;
    }
    balance1(current);
    return current;
  }
  // If the value is equal to what is stored, return the node
  else if (current->value == value){
    printf("Duplicate\n");
    return current;
  }
  // If the value is less than, add it to the left
  else if (current->value < value){
    addNumber(current, current->left, value);
    return current;
  }
  // Else it is greater than
  else {
     addNumber(current, current->right, value);
    return current;
  }
}

// A function for balancing the tree, case 1
void balance1(node* current){
  // If current is the root of the tree
  if ( !(current->parent) ){
    current->color = 'b';
    return;
  }
  // Elsewise go to the next case
  else {
    // Go on to the next cases
    balance2(current);
    return;
  }
}

// Case 2
void balance2(node* current){
  // If the parent is black
  if(current->parent->color == 'b'){
  }
  else{
    // Go on to the next cases
    balance3(current);
  }
  return;
}

// A function that balances the third case
void balance3(node* current){
  // If the uncle exists and both the parent and the uncle are red
  if (uncle(current) != NULL &&
      (uncle(current)->color == 'r' && current->parent->color == 'r')){
    // Recolor the uncle, the parent, and the grandparent
    uncle(current)->color       = 'b';
    current->parent->color      = 'b';
    grandparent(current)->color = 'r';
    // Balance the grandparent
    balance1(grandparent(current));
    return;
  }
  else{
    balance4(current);
    return;
  }
}

// A function for the fourth case
void balance4(node* current){
  // The uncle has to be black and the parent has to be red since
  // The parent has to be red otherwise case 2
  // The uncle has to be black otherwise case 3

  // Right Handed side, current is on the right and parent is on the left
  if (grandparent(current)->left == current->parent &&
      current ==  current->parent->right){
    // Left rotate at parent
    leftRotate(current->parent);
    // Move on to balance5
    balance5(current);
  }

  // Left handed side
  else if (grandparent(current)->right == current->parent &&
      current == current->parent->left){
    // Right rotate at parent
    rightRotate(current->parent);
    // Move on to balance5
    balance5(current);
  }
  else{
    balance5(current->parent);
  }
  

}

// A function for the fifth case of adding ot a red black tree
void balance5(node* current){
 // We assume that there is no other case 
 // Right case
 printf("parent %i\n", current->parent->value);
 if (current == current->parent->left){
   rightRotate(current->parent);
   current->color        = 'b';
   current->right->color  = 'r';
 }
 else{
   leftRotate(current->parent);
   current->color        = 'b';
   current->left->color = 'r';
 }
}

// A function that left rotates a tree
void leftRotate(node* current){
  // Saving a pointer to the child
  node* a = current->parent;
  node* b = current;
  node* c = current->right;
  node* cLeft = c->left;
  // Swap parents
  if(a){
  a->left   = c;
  }
  c->parent = a;
  c->left   = b;
  b->parent = c;
  // Swap children
  b->right = cLeft;
  // If the left child of c exists
  if(cLeft){
    cLeft->parent = b;
  }
}

// A function that right rotates a tree
void rightRotate(node* current){
  // Saving a pointer to the child
  node* a = current->parent;
  node* b = current;
  node* c = current->left;
  node* cRight = c->right;
  // Swap parents
  if(a){
  a->right    = c;
  }
  c->parent   = a;
  c->right    = b;
  b->parent   = c;
  // Swap children
  b->left = cRight;
  // If the right child of c exists
  if(cRight){
    cRight->parent = b;
  }
}

// A function the finds the uncle
node* uncle(node* current){
  // If the parent and grandparent exists
  if ((current->parent != NULL) && (current->parent->parent != NULL)){
    // If the left side is not equal to the current node, it is the uncle
    if (current->parent->parent->left != current->parent){
      return current->parent->parent->left;
    }
    // Else return the other side
    else{
      return current->parent->parent->right;
    }
  }
  // All other cases mean the uncle does not exist
  return NULL;
}

// A function that finds the grandparent
node* grandparent(node* current){
  // If the parent exists
  if (current->parent){
    return current->parent->parent;
  }
}

