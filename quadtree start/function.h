#include "stdio.h"
#include "stdlib.h"
#include "math.h"
struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
  int flag;
};
typedef struct qnode Node;

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growtree(Node *head);

double value( double x, double y, double time );
double nodeValue( Node *node, double time );

void destroyTree(Node *parent );
void removeChildren( Node *parent );
void giveflag(Node *head);
void changetree(Node *head);
void adapt( Node *head );



void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );

