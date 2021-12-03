#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, x1, y, y1;
    cin>>x>>y>>x1>>y1;
    if(x==x1){
        if(y<y1) x--;
        else x++;
    }
    if(y==y1){
        if(x<x1) y--;
        else y++;
    }
    int ans = (abs(x-x1)+1);
    int ans1 = (abs(y-y1)+1);
    cout<<((ans + ans1)*2)<<endl;

    return 0;
}
