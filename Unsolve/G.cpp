#include <bits/stdc++.h>
using namespace std;
struct node {
    node* NOD[26];
    bool ending;
    node() {
        for(int i=0; i<26; i++)
            NOD[i] = NULL;
        ending = 0;
    }
};
node *root = new node();
void add(string s) {
    node *current = root;
    for(auto c : s) {
        c -= 'a';
        if(current->NOD[c]==NULL)
            current->NOD[c] = new node();
        current = current->NOD[c];
    }
    current->ending=true;
}
int is_valid(string s) {
    node *current = root;
    for(auto c : s) {
        c -= 'a';
        if(current->NOD[c]==NULL)
            return 0;
        current = current->NOD[c];
    }
    return current->ending;
}
int main() {
    int N;
    string str;
    scanf("%d", &N);
    while(N--) {
        cin>>str;
        add(str);
    }
    int M;
    scanf("%d", &M);
    while(M--) {
        cin>>str;
        if(is_valid(str)>0) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}
