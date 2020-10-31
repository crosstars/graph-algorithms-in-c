#include<stdio.h>
#include<stdlib.h>

#define FILEN "set.txt"
#define GTYPE "undirected"

typedef struct gnode//graph node structure
  {
    int lbl;
    char colour;
    int weight;
    struct gnode* next;
  }gnode;

typedef struct label//graph naode list structure
  {
    int lbl;
    gnode* last;
    gnode* list;
  }label;

gnode* create_node(int next_node)//function to create a graph node dynamically
  {
    gnode* temp;
    temp = (gnode*)malloc(sizeof(gnode)*1);
    temp->lbl = next_node;
    temp->next = NULL;
    return temp;
  }

void pushnode(label* l,int lbl,int next_node)//function to insert the node in the nod list
  {
    gnode* temp = create_node(next_node);
    if(l[lbl-1].last==NULL)
      {
        l[lbl-1].last = temp;
        l[lbl-1].list = temp;
      }
    else
      {
        l[lbl-1].last->next =temp;
        l[lbl-1].last = temp;
      }
  }

void initialize(label* l,int node)
  {
    for(int i=0;i<node;i++)
      {
          l[i].lbl = i+1;
          l[i].last= NULL;
          l[i].list= NULL;
      }
  }

void take_input_list(FILE* fp,int node, label* l,int edges) //input the graph from the file
  {
    int lbl,next_node,c,i;
    gnode *temp;

    initialize(l,node);

    //c=fgetc(fp);
    i = 0;
    while( i++ < edges)
      {
        fscanf(fp,"%d %d\n",&lbl,&next_node);
        pushnode(l,lbl,next_node);
        if (GTYPE == "undirected")
          pushnode(l,next_node,lbl);
      }
  }

void showlist(label* l, int node)
  {
    int i;
    printf("vertices:  ");
    for(i=0;i<node;i++)
      printf(" %d , ",l[i].lbl);
    printf("\nedges:\n");

    for(i=0;i<node;i++)
      {
        gnode *p = l[i].list;
        while(p!=NULL)
          {
            printf("%d %d\n",i+1,p->lbl);
            p = p->next;
          }
      }
  }

  gnode* inMat(FILE *fp ,int node,int edges)
    {
      int u , v, weight =1,c;
      gnode* arr = (gnode*)malloc(node*node*sizeof(gnode));

      for (int i = 0; i < node; i++)
        for (int j = 0; j < node; j++)
          (arr + i*node + j)->weight = 0;

      int i=0;
      while( i++ < edges)
        {
          fscanf(fp,"%d %d\n",&u,&v);
          (arr+ (u-1)*node + (v-1))->weight = weight;
          if (GTYPE == "undirected")
            (arr+ (v-1)*node + (u-1))->weight = weight;
        }
      return(arr);
    }

  void showMat(gnode* arr,int node)
  {
    printf("adjacency list\n");
    for (int i = 0; i < node; i++)
      {
        for (int j = 0; j < node; j++)
          {
              printf("%2d",(arr + i*node + j)->weight);
          }
        printf("\n");
      }
  }


void main()
  {
    char fname[20];
    int n,edges;
    label g1[n];
    FILE *fp,*fp2;
    fp = fopen(FILEN,"r");

    fscanf(fp,"%d %d\n",&n ,&edges);
    gnode g[n][n];

    take_input_list(fp ,n, g1,edges);

    showlist(g1,n);
    fclose(fp);

    fp2 = fopen(FILEN,"r");

    fscanf(fp2,"%d %d\n",&n ,&edges);

    gnode* arr= inMat(fp2 ,n,edges);;
    
    showMat(arr,n);
    fclose(fp2);
  }
