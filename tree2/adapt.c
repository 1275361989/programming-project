#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define maxLevel 6
#include "treeStruction.h"
#include "function.h"

extern int addnode;                 //use the various from the main function
extern int removenode;
void giveflag(Node *node)
{
    if((node->child[0])==NULL)      //if the node is a leaf node
    {
        if (nodeValue(node,0)>0.5)//use the function"nodeValue", if it >0.5 ,set flag to 1
                node->flag=1;
        if(nodeValue(node,0 )<-0.5)//use the function"nodeValue", if it <-0.5 ,set a flag to -1
                node->flag=-1;
    }

}
void changetree(Node *node)
{
    if(node->child[0]==NULL)//if the node is leaf node
    {

        giveflag(node);     //give it flag
        if(node->level<maxLevel&&node->flag==1)   //if the flag is 1 and its level<6
            {

                makeChildren(node);              //make children and recored the node added
                addnode+=4;


            }
    }
    else if(node->child[0]!=NULL&&node->child[0]->child[0]==NULL)//if the node is not leaf but it children is leaf
    {

        int i,j=0;


        for(i=0;i<4;i++)
           {
               giveflag(node->child[i]);//give its children flag
               if(node->child[i]->flag==-1)//if its children's flag =-1
                j+=1;                     //use j to calculate
           }

        if(j==4)                            //if all four children's flag is -1
            {
                removenode+=4;             //calculate the node removed and remove the four children
                removeChildren(node);
            }
        else                                //if its four children's flag are not all -1
            {
                for(i=0;i<4;i++)
                changetree(node->child[i]);    //refer to its children
            }
    }
    else                //if the node is not leaf, its children are also not leaf
    {
        int i;
        for(i=0;i<4;i++)
            changetree(node->child[i]);//refer to its children
    }


}
void adapt( Node *node )
{
    do{
        addnode=0;
        removenode=0;
        changetree(node);
        printf("add: %d remove: %d\n",addnode,removenode);
    }while(addnode!=0&&removenode!=0);


}

