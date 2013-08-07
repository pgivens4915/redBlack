// Paul Givens
// Aug, 8 2013
// A Shell to test my red black tree
#include <stdio.h>
#include "tree.h"
main(){
  // Declarations
  node* root = NULL;
  root = addNumber(NULL, root, 20);
  root = addNumber(NULL, root, 10);
  root = addNumber(NULL, root, 25);
  root = addNumber(NULL, root, 5);
  root = addNumber(NULL, root, 43);
  root = addNumber(NULL, root, 22);
  root = addNumber(NULL, root, 11);
  printTree(root,0);
}
