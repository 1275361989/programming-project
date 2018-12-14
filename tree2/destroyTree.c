#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStruction.h"

void destroyTree( Node *parent )
{
  int i;
  if( parent->child[0] != NULL )//if the node is not a leaf node
    {
    for ( i=0; i<4; ++i )
       {
          destroyTree( parent->child[i]); //refer to its children
       }
       free(parent);                        //when finish free parent
       parent== NULL;                       //set to NULL
    }
  else                                      //if the node is a leaf node
    {
        free(parent);                       //free it and set to 0
        parent== NULL;
    }
}
