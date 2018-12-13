#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "function.h"
void destroyTree( Node *parent )
{

  int i;
  if( parent->child[0] != NULL )
    {
    for ( i=0; i<4; ++i )
       {
          destroyTree( parent->child[i]);
       }
       free(parent);
       parent== NULL;
    }
  else
    {
        free(parent);
        parent== NULL;
    }


}
