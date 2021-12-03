#include <bits/stdc++.h>
using namespace std;
struct node {
    int value;
    node *next, *prev;
    node() {
        next = NULL;
        prev = NULL;
    }
};
node *root=NULL, *till=NULL;
bool is_valid(int num){
    if(root==NULL) return false;
    node *now = root;
    while(now != NULL){
        if(now->value==num) return true;
        now = now->next;
    }
    return false;
}

void print_forward() {
    if(root==NULL) return;
    node *now = root;
    while(now != NULL) {
        printf("%d ", now->value);
        now = now->next;
    } puts("");
}
void print_backward() {
    if(root==NULL) return;
    node *now = till;
    while(now != NULL) {
        printf("%d ", now->value);
        now = now->prev;
    } puts("");
}

void Sorted_append(int value) {
    if(root==NULL) {
        root = new node();
        root->value = value;
        till = root;
    }
    else if(root->value>=value){
        node *New = new node();
        New->value = value;
        root->prev = New;
        New->next = root;
        root = New;
    }
    else if(till->value<=value){
        node *New = new node();
        New->value = value;
        New->prev = till;
        till->next = New;
        till = till->next;
    }
    else {
        node *current, *previous;
        current = previous = root;
        while(current->value<value){
            previous = current;
            current = current->next;
        }
        node *New = new node();
        New->value = value;
        New->prev = previous;
        New->next = current;

        previous->next = New;
        current->prev = New;
    }
}

void append(int value) {
    if(root==NULL) {
        root = new node();
        root->value = value;
        till = root;
    } else {
        node *New = new node();
        New->value = value;
        New->prev = till;
        till->next = New;
        till = till->next;
    }
}

void Delete(int num) {
    if(root==NULL) return;
    node *now = root;
    if(root->value==num) {
        if(root==till) {
            delete(root);
            root = NULL;
        } else {
            root = root->next;
            root->prev = NULL;
            delete(now);
        }
        return;
    }
    while(now->value!=num && now != NULL) {
        now = now->next;
    }
    if(now->value==num) {
        if(now==till) {
            till = now->prev;
            delete(now);
            till->next = NULL;
            return;
        }
        node *Prev = now->prev, *Next = now->next;
        Prev->next = Next;
        Next->prev = Prev;
        delete(now);
    }
}

int main() {
    int n;
    while(cin>>n && n){
        Sorted_append(n);
    }
    print_forward();
    print_backward();
    for(int i=5; i<11; i++) {
        if(is_valid(i)) puts("YES");
        else puts("NO");
    }
    for(int i=0; i<10; i++) {
        if(is_valid(i)) Delete(i);
        print_forward();
        print_backward();
    }
    return 0;
}
