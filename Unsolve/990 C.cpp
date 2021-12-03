#include <bits/stdc++.h>
using namespace std;
#define Size 300006
vector<string>Left[Size], Right[Size];
bool balanced(string expr);
int Find(string str);
int main() {
    //freopen("input.txt", "r", stdin);
    long long currect = 0;
    string str;
    int n, side;
    map<string, long long>Map;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        cin>>str;
        if(balanced(str))
            currect++;
        else {
            if((++Map[str])>1){
                continue;
            }
            else Map[str] = 1;
            side = Find(str);
            if(side<0) Right[abs(side)].push_back(str);
            else Left[side].push_back(str);
        }
    }
    //for(auto it : Map) cout<<it.first<<" "<<it.second<<endl;
    long long ans = currect*currect;
    for(int i=0; i<Size; i++){
        if(Left[i].size() && Right[i].size()){
            for(auto itR : Right[i]){
                for(auto itL : Left[i]){
                    if(balanced(itR+itL))ans += (Map[itR]*Map[itL]);
                    else if(balanced(itL+itR)) ans += (Map[itR]*Map[itL]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
int Find(string str){
    int coun = 0;
    for(auto it : str){
        if(it=='(') coun++;
        else coun--;
    }
    return coun;
}
bool balanced(string expr) {
    stack<char> s;
    int len = expr.size();
    char a, b, c;
    for(int i=0; i<len; i++) {
        if (expr[i]=='(') {
            s.push(expr[i]);
        } else if(expr[i]==')') {
            if(s.empty())
                return false;
            s.pop();
        }
    }
    if(s.empty())
        return true;
    return false;
}
