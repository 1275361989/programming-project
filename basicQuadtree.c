
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define maxLevel 6
// tree data structure
int addnode=0;//quanju?
int removenode=0;
struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
  int flag;
};
typedef struct qnode Node;

// function definitions

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );

double value( double x, double y, double time );
double nodeValue( Node *node, double time );

void growtree(Node *head);
void destroyTree(Node *parent );
void removeChildren( Node *parent );
// int remo(Node *node);
void giveflag(Node *head);
void changetree(Node *head);
void adapt( Node *head );

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

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;
  node->flag=0;
  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

// write out the tree to file 'quad.out'

void writeTree( Node *head ) {

  FILE *fp = fopen("quad.out","w");

  writeNode(fp,head);

  fclose(fp);

  return;
}

// recursively visit the leaf nodes

void writeNode( FILE *fp, Node *node ) {

  int i;

  if( node->child[0] == NULL )
    printOut( fp, node );
  else {
    for ( i=0; i<4; ++i ) {
      writeNode( fp, node->child[i] );
    }
  }
  return;
}

void destroyTree( Node *parent )
{

  int i;
  if( parent->child[3] == NULL )
    free(parent);
  else
    {
    for ( i=0; i<4; ++i )
       {
          destroyTree( parent->child[i]);
          parent->child[i] == NULL;
       }
    destroyTree(parent);

    return;
    }
}
void growtree(Node *node)
{
    if(node->child[0]==NULL)
        makeChildren(node);
    else
    {
        int i;
        for(i=0;i<4;i++)
           growtree(node->child[i]);
    }

}
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

// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time )
{

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time )
{
  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

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



void adapt( Node *node )//bianli
{
    if(node->child[0]==NULL)
    {
        printf("h1");
        giveflag(node);
        if(node->level<maxLevel&&node->flag==1)
            {
                printf("so");
                makeChildren(node);
                /*m=remo(node);
                if(m==1)
                    return; */
                int i;
                for (i=0;i<4;i++)
                {
                    printf("love\n");
                    addnode+=1;
                    adapt(node->child[i]);
                }
            }
    }
    else if(node->child[0]!=NULL&&node->child[0]->child[0]==NULL)
    {
        printf("h2");
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
         printf("h3");
        int i;
        for(i=0;i<4;i++)
            adapt(node->child[i]);
    }


}
/*int remo(Node *node)
{
    if(node->child[0]!=NULL&&node->child[0]->child[0]==NULL)
    {
        int i,j=0;
        for(i=0;i<4;i++)
            flag=giveflag(node->child[i]);
        for(i=0;i<4;i++)
           {
               if(node->child[i]->flag==-1)
                j+=1;
           }
        if(j==4)
            {
                removenode+=4;
                removeChildren(node);//deliver d duixang
                adapt(node);
            }
    }
    return 1;
}

*/



// write out the (x,y) corners of the node

void printOut( FILE *fp, Node *node ) {
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}
