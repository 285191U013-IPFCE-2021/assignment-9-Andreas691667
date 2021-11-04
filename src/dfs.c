/*
 * Search an expression using DFS.
 */
#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.

  /* This function uses recursion to traverse and print all the elements in a tree that consists only of integers.
  *  It starts from the root of the tree and prints the left childs first.
  *  Everytime a note without a child is reached, the right child to the current root is examined.
  *  Given a binary tree:
  *   
  *     77    23 3    9
  *       \   /   \  /
  *        28      86 
  *           \   /       
  *             7      98
  *               \   /
  *                 4
  * 
  * The sequence 4 7 28 77 23 86 3 9 98 will thus be printed.
  * 
  * NOTE: I've chosen to take advantage of the call stack, that C uses. Moreover, i've used recursion
  * to solve the problem. It is also possible to implement the function without recursion by implementing 
  * the whole tree as a new stack. Then the the pop and push functions could be used.
  * However, I find this solution more efficient (hope it still solves the exercise...:-)
  */

    //base case: the tree is empty
    if (root == NULL) { 
        printf ("NULL\n");
        return;
    }
    //The current element is printed, and is marked as visited
    else {
        print_node(root);
        root->visited = true;
    }
 
    //recursive step 1: The left childs are printed first
    if (root->lchild)
    {
        DFT(root->lchild);
    }
    
    //recursive step 2: The right childs are printed next
    if (root->rchild)
        DFT(root->rchild);

    return;

}

node *make_node (int num, node * left, node * right)
{
	node *new_node = malloc(sizeof(node));

  new_node->num = num;
  new_node->visited = false;
  new_node->rchild = right;
  new_node->lchild = left;

  return new_node;
}

void free_node (node * p)
{
	free(p);
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d ", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
	
  return 0;
}

bool isEmpty (stack * topp)
{
  return false;
}

node *top (stack * topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
	return 0;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
