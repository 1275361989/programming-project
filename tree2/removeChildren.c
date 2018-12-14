#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStruction.h"

void removeChildren( Node *parent ){
    int i;
    for ( i=0; i<4; ++i )
    {
        if(parent->child[i]->child[0]==NULL&&parent->child[i]!=NULL)//if the node is not leaf but its child is leaf
        {

            {
                free(parent->child[i]);//free its children
                parent->child[i]=NULL;//set to 0
            }//free
        }

    }

}
