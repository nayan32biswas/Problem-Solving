#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    int coun = 0;
    stack<char>stk;
    for(int i=0; i<str.size(); i++){
        if(stk.empty())
            stk.push(str[i]);
        else{
            if(stk.top()==str[i]){
                stk.pop();
                coun++;
            }else{
                stk.push(str[i]);
            }
        }
    }
    printf((coun&1) ? "Yes" : "No");
    return 0;
}