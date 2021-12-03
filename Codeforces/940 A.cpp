#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n, k, A, B;
int main() {
    cin>>n>>k>>A>>B;
    if(k==1) {
        cout<<A*(n-1)<<endl;
        return 0;
    }
    ull Max, x, coun=0, parfect;
    Max = A*(n-1);
    while(n>1) {
        if(n<k) {
            coun += (n-1)*A;
            break;
        }
        parfect = (n/k)*k;
        coun += (n-parfect)*A;
        coun += B;
        parfect/=k;
        n = parfect;
    }
    cout<<min(Max, coun)<<endl;
    return 0;
}
