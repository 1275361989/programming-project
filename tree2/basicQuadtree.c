#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStruction.h"
#include "buildTree.h"
#include "function.h"
#include "adapt.h"
#include "destroyTree.h"
#include "removeChildren.h"
#include "writeTree.h"
#define maxLevel 6
// tree data structure
int addnode=0;// calculate the node added in each stage
int removenode=0;//calculate the node removed in each stage

// function definitions

// main

int main( int argc, char **argv ) {

  Node *head;

                                                        // make the head node
  head = makeNode( 0.0,0.0, 0 );

                                                    // make a tree
    makeChildren(head);
    growtree(head);
    removeChildren(head->child[0]);
   //growtree(head);
   //changetree(head);                              //task3 need
   //printf("add: %d remove: %d\n",addnode,removenode);
    //adapt(head);                                  //task3 extended need
  //makeChildren( head->child[1] );
  destroyTree(head);
  // print the tree for Gnuplot
	writeTree( head );

  return 0;
}

// make a node at given location (x,y) and level




// Data function



// write out the (x,y) corners of the node

