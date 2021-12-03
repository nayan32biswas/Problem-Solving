#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a="aabb";
    int n, remain;
    cin>>n;
    remain = n%4;
    n/=4;
    for(int i=0; i<n; i++)cout<<a;
    for(int i=0; i<remain; i++)cout<<a[i];
    cout<<endl;
    return 0;
}
