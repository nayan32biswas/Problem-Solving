#include <bits/stdc++.h>
using namespace std;
struct node{
    char ch;
    int mark;
    node *next;
    node(char C, int M){
        ch = C;
        mark = M;
        next = NULL;
    }
};
struct vartex{
    node *V;
    vartex *next;
    vartex(node *v){
        V = v;
        next = NULL;
    }
};
vartex *root;
vartex *insert_vartex(char a){
    vartex *now = root;
    while(now->next != NULL && (now->next->V->ch) < a) {
        now = now->next;
    }
    if(now->next != NULL && now->next->V->ch==a) return now->next;
    vartex *temp = new vartex(new node(a, 0));
    temp->next = now->next;
    now->next = temp;
    return temp;
}
void add(char a, char b){
    node *now = insert_vartex(a)->V;
    while(now->next != NULL && now->next->ch < b){
        now = now->next;
    }
    if(now->next != NULL && now->next->ch == b) return;
    node *temp = new node(b, 0);
    temp->next = now->next;
    now->next = temp;
}
void print(){
    vartex *now = root;
    node *child;
    while(now != NULL){
        child = now->V;
        cout<<child->ch<<": ";
        while(child->next != NULL){
            printf("%c ", child->next->ch);
            child = child->next;
        }
        puts("");
        now = now->next;
    }
}
int main()
{
    root = new vartex(new node('1', 0));
    add('a', 'b');
    add('b', 'a');
    add('a', 'c');
    add('c', 'a');
    print();
}
