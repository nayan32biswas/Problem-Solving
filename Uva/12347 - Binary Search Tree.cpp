#include <bits/stdc++.h>
using namespace std;
struct node {
    int value;
    node *left, *right;
    node() {
        left = NULL;
        right = NULL;
    }
    node(int temp) {
        value = temp;
        left = NULL;
        right = NULL;
    }
};
node *root = NULL;
void add(int value) {
    if(root==NULL) {
        root = new node(value);
        return;
    }
    node *current = root, *parent;
    while(current!=NULL) {
        parent = current;
        if(current->value<value) current = current->right;
        else if(current->value>value) current = current->left;
        else return;
    }
    if(parent->value<value) parent->right = new node(value);
    else parent->left = new node(value);
}
vector<int>ans;
void print(node *current) {
    if(current==NULL) return;
    print(current->left);
    print(current->right);
    printf("%d\n", current->value);
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d", &n)!=EOF){
        add(n);
    }
    print(root);

}
