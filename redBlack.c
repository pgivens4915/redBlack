// Paul Givens
// Aug, 8 2013
// A Shell to test my red black tree
#include <stdio.h>
#include "tree.h"

node* findRoot(node* current);

main(){
  // Declarations
  node* root = NULL;
  root = addNumber(NULL, root, 10);
  root = findRoot(root);
  root = addNumber(NULL, root, 85);
  root = findRoot(root);
  root = addNumber(NULL, root, 15);
  root = findRoot(root);
  root = addNumber(NULL, root, 70);
  root = findRoot(root);
  root = addNumber(NULL, root, 20);
  root = findRoot(root);
  root = addNumber(NULL, root, 60);
  root = findRoot(root);
  root = addNumber(NULL, root, 30);
  root = findRoot(root);
  root = addNumber(NULL, root, 50);
  root = findRoot(root);
  root = addNumber(NULL, root, 65);
  root = findRoot(root);
  root = addNumber(NULL, root, 80);
  root = findRoot(root);
  root = addNumber(NULL, root, 90);
  root = findRoot(root);
  root = addNumber(NULL, root, 40);
  root = findRoot(root);
  root = addNumber(NULL, root, 5);
  root = findRoot(root);
  root = addNumber(NULL, root, 55);
  root = findRoot(root);
  

  printTree(root,0);


}

node* findRoot(node* current){
  if (current->parent){
    return findRoot(current->parent);
  }
  else{
    return current;
  }
}
