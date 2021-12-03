#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    long long k;
    cin>>n>>m>>k;
    if(n==1){
        return cout<<"1 "<<(k+1)<<endl, 0;
    }
    if(k<n){
        return cout<<(k+1)<<" 1"<<endl, 0;
    }
    k -= n;
    if(k==0){
        return cout<<n<<" 2"<<endl, 0;
    }
    m--;
    int N = n-(k/m), M = m+1;
    k %= m;
    //cout<<N<<" "<<k<<" "<<M<<endl;
    if(N%2==1){
        M = M-k;
    }
    else{
        M = k+2;
    }
    cout<<N<<" "<<M<<endl;
    return 0;
}
