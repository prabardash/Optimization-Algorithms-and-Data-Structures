#include<stdio.h>
#include<stdlib.h>

struct node {
  int vertex;
  struct node *next;
};

struct stacknode{
  int key;
  struct stacknode *next;
};

struct stacknode *stackptr = NULL;

void push(int key){
  struct stacknode *block = (struct stacknode *)malloc(sizeof(struct stacknode));
  block->key = key;
  block->next = NULL;
  if(stackptr == NULL){
    stackptr = block;
    stackptr->next  = NULL;
  }
  else{
    block->next = stackptr;
    stackptr = block;
  }
}

int pop(){
  int keyvalue = stackptr->key;
  struct stacknode * free_element;
  if(!stackptr) return -1;
  else {
    keyvalue = stackptr->key;
    free_element = stackptr;
    stackptr = stackptr->next;
    free(free_element);
  }
  return keyvalue;
}


void addedge(struct node **list, int u, int v)
{
  struct node * blocku = (struct node *)malloc (sizeof(struct node));
  blocku->vertex = u;
  struct node * blockv = (struct node *)malloc(sizeof(struct node));
  blockv->vertex = v;
  struct node * curr;

  if(list[u]==NULL){
        list[u] = blockv;
        blockv->next = NULL;
  }
  else{
    curr = list[u];
    while(curr->next != NULL) curr = curr->next;
    curr->next = blockv;
    blockv->next = NULL;
  }

  if(list[v]==NULL){
    list[v]=blocku;
    blocku->next = NULL;
  }
  else{
    curr = list[v];
    while(curr->next!=NULL) curr = curr->next;
    curr->next = blocku;
    blocku->next = NULL;
  }
  printf("\nNodes created, Edge added\n");
}

void dfs(int start_vertex, struct node **list){
  int val;
  int visited[10] = {0};
  struct node *neighbour=NULL;
  push(start_vertex);
  while(stackptr){
    val = pop();
    if(val!=-1 && visited[val]==0){
      printf("%d\n",val);
      visited[val]= 1;
    }
    //push its neighbours
    neighbour = list[val];
    while(neighbour){
      if(visited[neighbour->vertex]==0) push(neighbour->vertex);
      neighbour = neighbour->next;
    }
  }
}



void main()
{
  struct node *list[10]={NULL};
  int n,inp=1,u,v,weight;

  while(inp==1){
    printf("Create a graph with max 10 nodes\n");
    printf("Enter u, v [give a space between the two]= ");
    scanf("%d",&u);
    scanf("%d", &v);
    addedge(list,u,v);
    printf("\nCreate another edge?(1/0): ");
    scanf("%d",&inp);
  }
  int vx = list[0]->vertex;
  //printf("\n%d\n",vx);
  dfs(0,list);
}
