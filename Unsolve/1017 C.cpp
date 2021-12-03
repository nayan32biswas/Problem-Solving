#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int m = sqrt(n);
    for(int i=0; i<n; i++){
        cout<<max(n-m*(i/m+1),0)+i%m+1<<" ";
    }
    puts("");
}
