#include <bits/stdc++.h>
using namespace std;
#define length 10
struct node{
    bool ck;
    node *arr[length];
    node(){
        ck = 0;
        for(int i=0; i<length; i++) arr[i]=NULL;
    }
};
node *root = new node();
bool add(string s){
    node *current = root;
    int len = s.size();
    for(int i=0; i<len; i++){
        char c = s[i]-'a';
        if(current->arr[c]==NULL){
            current->arr[c] = new node();
        }
        else if(i+1==len) return true;
        current = current->arr[c];
        if(current->ck && i+1!=len) return true;
    }
    current->ck = true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    string text;
    cin>>test;
    cin.ignore();
    while(test--){
        cin>>text;
        if(add(text)){
            puts("BAD SET");
            return 0;
        }
    }
    puts("GOOD SET");
    return 0;
}
