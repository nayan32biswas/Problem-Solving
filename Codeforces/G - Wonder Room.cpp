#include <bits/stdc++.h>
using namespace std;
vector<int>fact;
bool fact(long long num){
    fact.clear();
    long long n = num;
    for(i=2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            fact.push_back(i);
        }
    }
    if(n==num) return false;
    return true;
}
int main()
{
    long long a, b, n, num, x, y;
    int len;
    cin>>n>>a>>b;
    n*=6;
    num = a*b;
    if(num>=n) printf("%lld\n%lld %lld\n", num, a, b), 0;
    bool ck=false;
    if(a>b)ck=true, swap(a, b);



    if(ck) swap(a, b);
    printf("%lld\n%lld %lld\n", num, a, b);
    return 0;
}
