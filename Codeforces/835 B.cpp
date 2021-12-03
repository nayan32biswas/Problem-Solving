#include <bits/stdc++.h>
using namespace std;
char n[100009];
int main()
{
    int i, k, len, ans=0;
    long long sum=0;
    scanf("%d%s", &k, n);
    len = strlen(n);
    for(i=0; i<len; i++){
        n[i]-='0';
        sum+=n[i];
    }
    sort(n, n+len);
    if(sum<k)for(i=0 ; i<len; i++){
        sum+=(9-n[i]);
        ans++;
        if(sum>=k) break;
    }
    cout<<ans<<endl;

}
