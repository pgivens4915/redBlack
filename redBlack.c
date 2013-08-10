// Paul Givens
// Aug, 8 2013
// A Shell to test my red black tree
#include <stdio.h>
#include "tree.h"
main(){
  // Declarations
  node* root = NULL;
  root = addNumber(NULL, root, 50);
  root = addNumber(NULL, root, 25);
  root = addNumber(NULL, root, 75);
  root = addNumber(NULL, root, 14);
  
  printTree(root,0);


}
