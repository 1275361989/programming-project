#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "function.h"
#define maxLevel 6
// tree data structure
int addnode=0;
int removenode=0;

// function definitions

// main

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
    makeChildren(head);
    growtree(head);
    growtree(head);
    do{
        addnode=0;
        removenode=0;
        adapt(head);
        printf("add %d remove %d",addnode,removenode);
    }while(addnode!=0&&removenode!=0);

  //makeChildren( head->child[1] );
  //destroyTree(head);
  // print the tree for Gnuplot
	writeTree( head );

  return 0;
}

// make a node at given location (x,y) and level




// Data function



// write out the (x,y) corners of the node

