#include <bits/stdc++.h>
using namespace std;
unsigned long long poW(int n){
    unsigned long long pow=1;
    for(int i=0; i<n; i++){
        pow*=2;
    }
    return pow;
}
int main()
{
    unsigned long long pow=1, n, m;
    cin>>n>>m;
    if(n>40) cout<<m<<endl;
    else {
        cout<<m%poW(n)<<endl;
    }
}
