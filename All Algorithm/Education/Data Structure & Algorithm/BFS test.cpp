#include <stdio.h>
#include <string.h>
#define Size 100
struct node{
    int value;
    node *next;
    node(int v){
        value = v;
        next = NULL;
    }
};

void push(node *temp, int value);
void print(node *temp);
int Front(node *temp);
bool Empty(node *temp);

node *graph[Size];
int dis[Size];

void bfs(int start, int End){
    memset(dis, 0, sizeof(dis));
    node *now, *Que;
    Que = new node(0);
    push(Que, start);
    while(!Empty(Que)){
        int T = Front(Que);
        now = graph[T];
        now = now->next;
        while(now!=NULL){
            if(dis[now->value]==0){
                dis[now->value] = dis[T]+1;
                push(Que, now->value);
            }
            now = now->next;
        }
    }
    printf("%d\n", dis[End]);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int N, edge, x, y;
    scanf("%d%d", &N, &edge);
    for(int i=0; i<=N; i++){
        graph[i] = new node(0);
    }

    for(int i=0; i<edge; i++){
        scanf("%d%d", &x, &y);
        push(graph[x], y);
        push(graph[y], x);
    }
    bfs(1, 8);

    return 0;
}

int Front(node *temp){
    if(temp->next==NULL) return -1;
    node *T = temp->next;
    temp->next = temp->next->next;
    int t = T->value;
    delete(T);
    return t;
}
bool Empty(node *temp){
    if(temp->next==NULL) return true;
    return false;
}
void push(node *temp, int value){
    if(temp->next==NULL) {
        temp->next = new node(value);
        return;
    }
    push(temp->next, value);
}
void print(node *temp){
    if(temp==NULL) return;
    printf("%d ", temp->value);
    print(temp->next);
}


