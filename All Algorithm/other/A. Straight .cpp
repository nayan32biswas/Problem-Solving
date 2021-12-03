#include <bits/stdc++.h>
using namespace std;
long long MAX(double num){
    long long n=num;
    if((num-n)>=(0.4999999999999)) n++;
    return n;
}
int main()
{
    int i, j, n, k, x, sum, ans;
    scanf("%d%d", &n, &k);
    for(i=0, sum=0; i<n; i++){
        scanf("%d", &x);
        sum+=x;
    }
    ans = n;
    long long temp=MAX((double)sum/ans);
    while(temp!=k){
        sum+=k;
        ans++;
        temp = MAX((double)sum/ans);
    }
    ans-=n;
    cout<<ans<<endl;
}
