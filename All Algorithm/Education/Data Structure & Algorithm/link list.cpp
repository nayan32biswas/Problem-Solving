#include <bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node *next, *prev;

    node(node *till, int V){
        value = V;
        next = NULL;
        prev = till;
    }
};
node *root, *till;
void add(int value){
    if(root==NULL){
        root = new node(till, value);
        till = root;
    }
    else{
        till->next = new node(till, value);
        till = till->next;
    }
}
void forword(){
    node *current = root;
    while(current!=NULL){
        cout<<current->value<<" ";
        current = current->next;
    }
    puts("");
}
void backword(){
    node *current = till;
    while(current!=NULL){
        cout<<current->value<<" ";
        current = current->prev;
    }
    puts("");
}
int main()
{
    root = NULL;
    till = NULL;
    for(int i=0; i<10; i++)add(i);
    forword();
    backword();
}
