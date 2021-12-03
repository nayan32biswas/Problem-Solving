#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int temp) {
        data = temp;
        left = NULL;
        right = NULL;
    }
};
node *root = NULL;
void add(int data) {
    if(root==NULL) {
        root = new node(data);
        return;
    }
    node *current = root, *parent;
    while(current!=NULL) {
        parent = current;
        if(current->data<data) current = current->right;
        else if(current->data>data) current = current->left;
        else return;
    }
    if(parent->data<data) parent->right = new node(data);
    else parent->left = new node(data);
}
void pre_order(node *current) {
    if(current==NULL) return;
    printf("%3d", current->data);
    pre_order(current->left);
    pre_order(current->right);
}
void in_order(node *current) {
    if(current==NULL) return;
    in_order(current->left);
    printf("%3d", current->data);
    in_order(current->right);
}
void post_order(node *current) {
    if(current==NULL) return;
    post_order(current->left);
    post_order(current->right);
    printf("%3d", current->data);
}
bool Find(int data, node *current){
    if(current==NULL) return false;
    if(current->data==data) return true;
    if(current->data>data) return Find(data, current->left);
    else return Find(data, current->right);
}
int main() {
    int arr[] = {10, 12, 9, 5, 2, 3, 11, 13, 6};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n; i++) add(arr[i]);

    pre_order(root);puts("");
    in_order(root);puts("");
    post_order(root);puts("");
    return 0;
}
