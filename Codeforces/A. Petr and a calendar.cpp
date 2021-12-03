#include <bits/stdc++.h>
using namespace std;
int sto[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int m, d, x, i, ans=4;
    cin>>m>>d;
    m = sto[m-1]+d-1;
    d = m/7;
    if(m%7==0)cout<<d<<endl;
    else cout<<d+1<<endl;
    return 0;
}
