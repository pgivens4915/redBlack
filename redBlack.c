// Paul Givens
// Aug, 8 2013
// A Shell to test my red black tree
#include <stdio.h>
#include "tree.h"
main(){
  // Declarations
  node* root = NULL;
  root = addNumber(NULL, root, 20);
  root = addNumber(NULL, root, 19);
  root = addNumber(NULL, root, 21);
  
  printTree(root,0);
}
