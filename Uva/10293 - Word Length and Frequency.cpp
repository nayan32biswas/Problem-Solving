#include <bits/stdc++.h>
using namespace std;
map<int, int>ans;
#define breker(ch) ( ch==' ' || ch=='?' || ch=='!' || ch==',' || ch=='.' )
void solve(string &str){
    ans.clear();
    int temp = 0;
    for(auto it : str){
        if(breker(it)){
            if(temp)ans[temp]++;
            temp = 0;
        }
        else if(isalpha(it)){
            temp++;
        }
    }
    if(temp)ans[temp]++;
    for(auto it : ans){
        printf("%d %d\n", it.first, it.second);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string str, temp;
    int test = 0;
    while(getline(cin, str)){
        while(getline(cin, temp) && temp!="#"){
            if(str.back()=='-')str+=temp;
            else str += (" "+temp);
        }
        if(test++)puts("");
        solve(str);
    }
    return 0;
}
