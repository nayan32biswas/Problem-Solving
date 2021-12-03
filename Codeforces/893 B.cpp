#include <bits/stdc++.h>
using namespace std;
int n, m, i, s[] = {1, 6, 28, 120, 496, 2016, 8128, 32640, 130816};
int main() {
    cin>>n;
    for(i=0; i<9; i++)if(n%s[i]==0)m = max(m, s[i]);
    cout<<m;
    return 0;
}

