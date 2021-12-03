#include<bits/stdc++.h>
using namespace std;
int main () {
    //freopen("input.txt", "r", stdin);
    long long n, m;
    while (cin>>n && n) {
        m = 1;
        while(m<n) {
            m*= 2;
            m++;
        }
        if(m==n) puts("Bob");
        else puts("Alice");
    }
    return 0;
}

