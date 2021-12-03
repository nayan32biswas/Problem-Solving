#include <bits/stdc++.h>
#define N 1000009
using namespace std;
int main()
{
    int i, j, k, n;
    cin>>n;
    k=n>>1;
    cout<<k<<endl;
    while(n>3){
        cout<<2<<' ';
        n-=2;
    }
    if(n>0)
        cout<<n<<endl;
    return 0;
}
