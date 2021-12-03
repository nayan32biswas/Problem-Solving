#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int>M;
    int a, b;
    cin>>a>>b;
    int x = abs(a-b);
    int ans = 0;
    for(int i=1; i<=x; i++){
        ans += i;
        M[i] = ans;
    }
    M[0]=0;
    int Min=9999999;
    ans = 0;
    for(int i=1; i<=x; i++){
        ans += i;
        if(M[x-i] || x-i==0){
            Min = min(Min, ans+M[x-i]);
        }
    }
    cout<<Min<<endl;
    return 0;
}
