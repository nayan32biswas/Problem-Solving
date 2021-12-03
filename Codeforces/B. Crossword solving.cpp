#include <bits/stdc++.h>
using namespace std;
string s, t;
int m, n;
vector<int>ans;

int check(int i){
    int dif=0, j;
    for(j=0; j<n; j++, i++){
        if(s[j]!=t[i]) dif++;
    }
    return dif;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    cin>>s>>t;
    int start=0, Min = n, x, i, j;
    for(i=0; i<=(m-n); i++){
        x = check(i);
        if(x<Min){
            Min = x;
            start=i;
        }
    }
    ans.clear();

    for(i=start, j=0; i<start+n; i++, j++) if(s[j]!=t[i]) ans.push_back(j+1);
    cout<<ans.size()<<endl;
    for(int value: ans) cout<<value<<' ';
    cout<<endl;
}
