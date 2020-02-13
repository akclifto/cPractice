/*Learn-c.org Binary Tree Exercise
    Below is an implementation of a binary tree that has insertion and printing capabilities.
    This tree is ordered but not balanced. 
    This example maintains its ordering at insertion time.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node * left;
  struct node * right;
} node_t;

void insert(node_t * tree,int val);
void print_tree(node_t * current);
void printDFS_preorder(node_t * current);
void printDFS_postorder(node_t * current);
void printDFS_inorder(node_t * current);

int main()
{
  node_t * test_list = (node_t *) malloc(sizeof(node_t));
  /* set values explicitly, alternative would be calloc() */
  test_list->val = 0;
  test_list->left = NULL;
  test_list->right = NULL;

  /*insert test values in tree*/
  insert(test_list,5);
  insert(test_list,8);
  insert(test_list,4);
  insert(test_list,3);

  //print different traversals types.
  printf("pre-order: ");
  printDFS_preorder(test_list);
  printf("\n");
  printf("post-order: ");
  printDFS_postorder(test_list);
  printf("\n");
  printf("inorder: ");
  printDFS_inorder(test_list);
  printf("\n");
}

void insert(node_t * tree, int val)
{
  if (tree->val == 0) {
    /* insert on current (empty) position */
    tree->val = val;
  } else {

    if (val < tree->val) {
      /* insert left */
      if (tree->left != NULL) {
        insert(tree->left, val);
      } else {

        tree->left = (node_t *) malloc(sizeof(node_t));
        /* set values explicitly, alternative would be calloc() */
        tree->left->val = val;
        tree->left->left = NULL;
        tree->left->right = NULL;
      }
    } else {
        
      if (val >= tree->val) {
        /* insert right */
        if (tree->right != NULL) {
          insert(tree->right,val);
        } else {
          tree->right = (node_t *) malloc(sizeof(node_t));
          /* set values explicitly, alternative would be calloc() */
          tree->right->val = val;
          tree->right->left = NULL;
          tree->right->right = NULL;
        }
      }
    }
  }
}


/* depth-first search, pre-order */
void printDFS_preorder(node_t * current)
{
  /* change the code here. CHANGED */
  if (current == NULL)         return;   /* security measure */
  if (current != NULL)         printf("%d ", current->val);           // read the current node in the tree.
  if (current->left != NULL)   printDFS_preorder(current->left);      // check left, then recursive call
  if (current->right != NULL)  printDFS_preorder(current->right);     // check right, then recursive call

}

/* depth-first search, post-order */
void printDFS_postorder(node_t * current)
{
  /* change the code here. CHANGED */
  if (current == NULL)         return;   /* security measure */
  if (current->left != NULL)   printDFS_postorder(current->left);      // check left, then recursive call
  if (current->right != NULL)  printDFS_postorder(current->right);     // check right, then recursive call
  if (current != NULL)         printf("%d ", current->val);            // read the current node in the tree.

}

/* depth-first search, in-order */
void printDFS_inorder(node_t * current)
{
  /* change the code here. CHANGED */
  if (current == NULL)         return;   /* security measure */
  if (current->left != NULL)   printDFS_inorder(current->left);      // check left, then recursive call
  if (current != NULL)         printf("%d ", current->val);          // read the current node in the tree.
  if (current->right != NULL)  printDFS_inorder(current->right);     // check right, then recursive call
