#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>V;
bool Find(int x){
    int TT = 0, num = x;
    while(x>0){
        TT+=(x%10);
        x/=10;
    }
    if(num+TT==n) return true;
    return false;
}
int main()
{
    cin>>n;
    int End = max(0, n-200);
    for(int i=n; i>End; i--){
        if(Find(i)){
            V.push_back(i);
        }
    }
    reverse(V.begin(), V.end());
    cout<<V.size()<<endl;
    for(auto a : V){
        cout<<a<<endl;
    }
}
