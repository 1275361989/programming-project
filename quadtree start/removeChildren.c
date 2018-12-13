#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "function.h"
void removeChildren( Node *parent ){
    int i;
    for ( i=0; i<4; ++i )
    {
        if(parent->child[i]->child[0]==NULL&&parent->child[i]!=NULL){
            {
                free(parent->child[i]);
                parent->child[i]=NULL;
            }//free
        }
        else
            return;
    }

}
