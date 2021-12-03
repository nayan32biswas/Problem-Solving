#include <bits/stdc++.h>
using namespace std;
struct node{
    bool End;
    node *zero, *one;
    node(){
        End = false;
        zero = NULL;
        one = NULL;
    }

}*root;
bool ck;
void add(string str){
    node *current = root;
    int i=0;
    for(auto a : str){
        if(current->End) ck = false;

        if(a=='0'){
            if(current->zero==NULL) current->zero = new node();
            else i++;
            current = current->zero;
        }
        else{
            if(current->one==NULL)current->one = new node();
            else i++;
            current = current->one;
        }

    }
    if(current->End) ck = false;
    if(str.size()==i) ck = false;
    current->End = true;
}
void Delete(node *current){
    if(current==NULL) return;
    Delete(current->zero);
    Delete(current->one);
    delete(current);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string str;
    int query = 0;
    while(cin>>str){
        if(str!="9"){
            ck = true;
            root = new node();
            add(str);
            while(cin>>str && str!="9"){
                if(ck) add(str);
            }
            printf("Set %d ", ++query);
            if(ck) puts("is immediately decodable");
            else puts("is not immediately decodable");
            delete(root);
        }
    }
    return 0;
}
