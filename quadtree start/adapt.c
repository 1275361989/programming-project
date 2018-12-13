#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define maxLevel 6
#include "function.h"
extern int addnode;
extern int removenode;
void giveflag(Node *node)
{
    if((node->child[0])==NULL)
    {
        if (nodeValue(node,0)>0.5)
                node->flag=1;
        if(nodeValue(node,0 )<-0.5)
                node->flag=-1;
    }

}


void adapt( Node *node )
{
    if(node->child[0]==NULL)
    {

        giveflag(node);
        if(node->level<maxLevel&&node->flag==1)
            {

                makeChildren(node);
                /*m=remo(node);
                if(m==1)
                    return; */
                int i;
                for (i=0;i<4;i++)
                {

                    addnode+=1;
                    adapt(node->child[i]);
                }
            }
    }
    else if(node->child[0]!=NULL&&node->child[0]->child[0]==NULL)
    {

        int i,j=0;
        for(i=0;i<4;i++)
            giveflag(node->child[i]);
        for(i=0;i<4;i++)
           {
               if(node->child[i]->flag==-1)
                j+=1;
           }

        if(j==4)
            {
                removenode+=4;
                removeChildren(node);
                //deliver d duixang
                adapt(node);
            }
        else
            {
                for(i=0;i<4;i++)
                adapt(node->child[i]);
            }
    }
    else
    {

        int i;
        for(i=0;i<4;i++)
            adapt(node->child[i]);
    }


}

