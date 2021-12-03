#include <bits/stdc++.h>
using namespace std;
struct node{
    bool ck;
    node *arr[10];
    node(){
        for(int i=0; i<10; i++) arr[i] = NULL;
        ck = false;
    }
};
node *root;
bool add(string s){
    node *current = root;
    int len = s.size();
    for(int i=0; i<len; i++){
        char c = s[i]-'0';
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
    int test, n;
    string s;
    cin>>test;
    while(test--){
        cin>>n;
        root = new node();
        bool ck=true;
        while(n--){
            cin>>s;
            if(add(s)) {
                puts("NO");
                ck = false;
                break;
            }
        }
        while(n-->0)cin>>s;

        if(ck) puts("YES");
    }
    return 0;
}
