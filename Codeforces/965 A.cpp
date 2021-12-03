#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int k, n, s, p, pack, page;
int Find(){
    while(n>0 && page>=k){
        page -= k;
        n -= s;
    }
}
int main() {
    cin>>k>>n>>s>>p;
    while(n>0){
        pack++;
        page += p;
        Find();
        //cout<<page<<" "<<n<<endl;
    }
    cout<<pack<<endl;
    return 0;
}
