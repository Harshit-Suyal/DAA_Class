#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;

void readgraph(node* [], int);
void printgraph(node* [], int);
void bfs(node* [], int, int, int []);
void dfs(node* [], int, int [], int);

int main() {
    int v, i, data, ch;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    int visited[v];
    node* adj[v];
    for (i = 0; i < v; i++) {
        adj[i] = NULL;
    }
    do {
        printf("1. Read Graph\n2. BFS Traversal\n3. DFS Traversal\n4. Print Graph\n0. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: readgraph(adj, v); break;
            case 2:
                printf("Enter the start node: ");
                scanf("%d", &data);
                for (i = 0; i < v; i++) visited[i] = 0;
                bfs(adj, data, v, visited);
                break;
            case 3:
                printf("Enter the start node: ");
                scanf("%d", &data);
                for (i = 0; i < v; i++) visited[i] = 0;
                printf("DFS Traversal: ");
                dfs(adj, v, visited, data);
                printf("\n");
                break;
            case 4: printgraph(adj, v); break;
            case 0: exit(0);
        }
    } while (ch != 0);
    return 0;
}

void readgraph(node* adj[], int v) {
    int i, j, k;
    node* newnode;
    for (i = 0; i < v; i++) {
        node* last = NULL;
        printf("How many vertices are adjacent to %d: ", i);
        scanf("%d", &k);
        for (j = 1; j <= k; j++) {
            newnode = (node*)malloc(sizeof(node));
            printf("Enter the %d neighbour of %d: ", j, i);
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            if (adj[i] == NULL) {
                adj[i] = newnode;
            } else {
                last->next = newnode;
            }
            last = newnode;
        }
    }
}

void printgraph(node* adj[], int v) {
    int i;
    node* temp;
    for (i = 0; i < v; i++) {
        printf("Vertices adjacent to %d are: ", i);
        temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void bfs(node* adj[], int st, int v, int visited[]) {
    int q[v], f = 0, r = 0;
    node* ptr;
    q[r] = st;
    visited[st] = 1;
    printf("BFS Traversal: ");
    while (f <= r) {
        st = q[f++];
        printf("%d ", st);
        ptr = adj[st];
        while (ptr != NULL) {
            if (!visited[ptr->data]) {
                q[++r] = ptr->data;
                visited[ptr->data] = 1;
            }
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void dfs(node* adj[], int v, int visited[], int st) {
    visited[st] = 1;
    printf("%d ", st);
    node* temp = adj[st];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(adj, v, visited, temp->data);
        }
        temp = temp->next;
    }
}
