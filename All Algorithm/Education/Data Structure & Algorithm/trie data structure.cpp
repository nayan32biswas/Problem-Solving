#include <bits/stdc++.h>
using namespace std;
struct node {
    node* NOD[26];
    int ending;
    node() {
        for(int i=0; i<27; i++) NOD[i] = NULL;
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
    current->ending++;
}
int is_valid(string s){
    node *current = root;
    for(auto c : s){
        c -= 'a';
        if(current->NOD[c]==NULL) return 0;
        current = current->NOD[c];
    }
    return current->ending;
}
int main() {
    add("nayan");
    add("ncyan");
    add("natan");
    add("natan");
    add("naxan");
    add("naxan");
    printf("%d\n", is_valid("nayannn"));
    printf("%d\n", is_valid("aatan"));
    printf("%d\n", is_valid("naxan"));
    printf("%d\n", is_valid("naaan"));
}
