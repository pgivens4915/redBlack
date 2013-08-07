// The red black tree header
typedef struct node node;

struct node{
  node* parent;
  node* child;
  int value;
};

void test();
