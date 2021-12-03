#include <bits/stdc++.h>
using namespace std;
int min(int x, int y){
    if(x>y)
        return y;
    return x;
}
int main()
{
    int y, b, r;
    cin>>y>>b>>r;
    y = min(y, min(b-1, r-2));
    b = min(b, min(y+1, r-1));
    r = b+1;
    cout<<y+b+r<<endl;
    return 0;
}