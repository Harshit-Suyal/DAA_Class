#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void readGraph(struct node *adj[],int v){
    struct node *newnode;
    int k,data;
    for(int i=0;i<v;i++){
        struct node *last = NULL;
        printf("Number of vertices adjacent to %d: ",i);
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            newnode = (struct node *)malloc(sizeof(struct node *));
            printf("Enter the %d neighbour of %d: ",j,i);
            scanf("%d",&data);
            newnode->data = data;
            newnode->next = NULL;
            if(adj[i]==NULL){
                adj[i] = newnode;
            }
            else{
                last->next = newnode;
            }
            last = newnode;
        }
    }
}

void printGraph(struct node *adj[],int v){
    struct node *temp;
    for(int i=0;i<v;i++){
        temp = adj[i];
        printf("\nVertices adjacent to %d are: ",i);
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        
    }
}

void bfs(struct node *adj[],int start,int visited[]);

void dfs(struct node *adj[],int start,int visited[]){
    visited[start] = 1;
    printf("%d ",start);
    struct node *ptr = adj[start];
    while(ptr!=NULL){
        if(visited[ptr->data]!=1){
            dfs(adj,ptr->data,visited);
        }
        ptr = ptr->next;
    }
}

int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    
    int ch,data,visited[v];
    struct node *adj[v];
    
    for(int i=0;i<v;i++){
        adj[i]= NULL;
    }
    
    readGraph(adj,v);
    
    do{
        printf("Enter 1 for BFS\nEnter 2 for DFS\nEnter 3 to Print Adjacency List\nEnter 4 to exit: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
            /*printf("Enter the vertex from which you are goind to start: ");
            scanf("%d",&data);
            for(int i=0;i<v;i++){
                visited[i] = 0;
            }
            bfs(adj,data,visited);
            break;
            */
            case 2:
            printf("Enter the vertex from which you are goind to start: ");
            scanf("%d",&data);
            for(int i=0;i<v;i++){
                visited[i] = 0;
            }
            dfs(adj,data,visited);
            break;
            case 3: printGraph(adj,v); break;
            case 4: break;
        }
    }while(ch!=4);
    return 0;
}