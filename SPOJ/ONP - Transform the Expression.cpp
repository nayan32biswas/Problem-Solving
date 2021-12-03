#include <bits/stdc++.h>
using namespace std;
stack < char > paren, algeb;
void Clear(){
    while(!paren.empty()) paren.pop();
    while(!algeb.empty()) algeb.pop();
}
int main()
{
    int len, test, i;

    string str;
    cin>>test;
    while(test--){
        cin>>str;
        Clear();
        for(auto c : str){
            if(c == (char)(40) ) paren.push(c);
            else if(c=='+' || c=='-' || c=='/' || c=='*' || c=='^'){
                algeb.push(c);
            }
            else if(c== ')') {
                paren.pop();
                printf("%c", algeb.top());
                algeb.pop();
            }
            else printf("%c", c);
        }
        puts("");
    }
    return 0;
}
