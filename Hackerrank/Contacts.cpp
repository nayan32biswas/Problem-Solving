#include <bits/stdc++.h>
using namespace std;
struct node{
    int pre;
    node *arr[26];
    node(){
        pre = 1;
        for(int i=0; i<26; i++) arr[i]=NULL;
    }
};
node *root = new node();
void add(string s){
    node *current = root;
    for(auto c : s){
        c-=97;
        if(current->arr[c]==NULL){
            current->arr[c] = new node();
        }
        else{
            current->arr[c]->pre++;
        }
        current = current->arr[c];
    }
}
int Find(string s){
    int len = s.size(), i;
    node *current = root;
    for(i=0; i<len; i++){
        char c = s[i]-97;
        if(current->arr[c]==NULL){
            return 0;
        }
        else{
            current = current->arr[c];
        }
    }
    return current->pre;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    string temp, text;
    cin>>test;
    cin.ignore();
    while(test--){
        cin>>temp>>text;
        if(temp=="add")
            add(text);
        else cout<<Find(text)<<endl;
    }
}
