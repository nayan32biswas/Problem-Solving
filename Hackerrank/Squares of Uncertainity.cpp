#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long x, y, x1, y1;
    int test;
    cin>>test;
    for(int t=0; t<test; t++){
        cin>>x>>y>>x1>>y1;
        if(x<x1) swap(x, x1);
        if(y<y1) swap(y, y1);
        cout<<max(x-x1, y-y1)<<endl;
    }
    return 0;
}
