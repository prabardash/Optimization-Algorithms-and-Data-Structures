#include<stdio.h>
#include<stdlib.h>

struct node{
  int vertex;
  int weight;
  struct node * next;
};

struct qnode{
  int val;
  struct qnode *next;
};
struct qnode *front=NULL, *rear=NULL;

void qinsert(int value)
{
  struct qnode * block=(struct qnode *)malloc(sizeof(struct qnode));
  block->val=value;
  block->next=NULL;
  if(rear!=NULL)
  {
    rear->next=block;
    rear=rear->next;
  }
  else
  {
    rear=block;
    front=block;
  }
}

int qdelete()
{
  if(front!=NULL)
  {
    struct qnode *temp=front;
    if(front == rear) rear=rear->next;
    front=front->next;
    int pop=temp->val;
    free(temp);
    return pop;
  }
  else{
    printf("\nERROR: Queue underflow\n");
    if(rear==NULL){printf("\n The rear is also null");}
    return -1;
  }
}

int bfs(int v, struct node ** list)
{
  printf("\n The nodes visited by BFS Algorithm are: \n");
  printf("\n%d\n",v);
  struct node *curr;
  int visited[10]={0};
  int u=v;
  visited[v]=1;
  while(1)
  {
    if(u!=-1) curr=list[u];
    else curr=NULL;
    while(curr!=NULL)
    {
      if(visited[curr->vertex]==0)
      {
        qinsert(curr->vertex);
        visited[curr->vertex]=1;
        printf("\n%d\n",curr->vertex);
      }
      curr=curr->next;
    }
    if(front==NULL && rear ==NULL) return 1;
    u=qdelete();
  }
  return 0;
}


void addedge(struct node **list, int u, int v, int weight)
{
  struct node *start=NULL;
  struct node *unode =(struct node *)malloc(sizeof(struct node));
  unode->weight=weight;
  unode->vertex=u;
  unode->next=NULL;

  struct node *vnode =(struct node *)malloc(sizeof(struct node));
  vnode->weight=weight;
  vnode->vertex=v;
  vnode->next=NULL;

  start= (list[u]);

  if(!start) {
    start=vnode;
    //printf("\n%d\n",start->vertex);
    list[u]=start;
  }
  else{
  while(start->next!=NULL)
    start=start->next;
  start->next=vnode;
  }

  printf("\n%d\n",start->vertex);

  start=list[v];
  if(!start) {
    start=unode;
    list[v]=start;
  }
  else{
  while(start->next!=NULL)
    start=start->next;
  start->next=unode;}
  printf("\n the edge has been added\n");
}

void main()
{
  struct node *list[10]={NULL};
  int n,inp=1,u,v,weight;

  while(inp==1){
    printf("Enter u v weight = ");
    scanf("%d",&u);
    scanf("%d", &v);
    scanf("%d",&weight);
    addedge(list,u,v,weight);
    printf("\nCreate another edge?(1/0) \n");
    scanf("%d",&inp);
  }
  int vx = list[0]->vertex;
  //printf("\n%d\n",vx);

  bfs(vx,list);
}
