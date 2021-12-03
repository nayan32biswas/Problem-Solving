#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, x;
    cin>>n;
    x = sqrt(n);
    while(((x*(x+1))/2)<n) {
        x++;
    }
    cout<<x<<endl;
    return 0;
}
