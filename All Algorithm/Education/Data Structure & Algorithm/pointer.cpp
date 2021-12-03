#include <iostream>
#include <cstdio>
using namespace std;
bool is_prime(int n){
    if(n<2) return false;
    if(n==2) return true;
    if(!(n&1)) return false;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    while(scanf("%d", &n) && n){
        if(is_prime(n)) puts("YES");
        else puts("NO");
    }
}
