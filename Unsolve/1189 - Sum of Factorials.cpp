#include <bits/stdc++.h>
using namespace std;
long long arr[23];
bool ck;
vector<int>ans;
void finde(int pos, long long n){
    if(!ck){
        long long x;
        int i;
        if(ck) return;
        for(i=pos; i<21; i++)if(arr[i]<=n){
            x = n-arr[i];
            if(ck) return;
            if(x>=0){
                ans.push_back(20-i);
                if(x==0){
                    ck=true;
                    return;
                }
                finde(i+1, x);
            }
        }
        if(ck) return;
    }
    if(ck) return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int i, len, test;
    unsigned long long temp, n;
    arr[0] = 1;
    for(i=1; i<21; i++) arr[i] = arr[i-1]*i;
    reverse(arr, arr+21);
    cin>>test;
    for(int t=1; t<=test; t++){
        ans.clear();
        ck = false;
        scanf("%lld", &n);
        printf("Case %d: ", t);
        if(n>(long long)(1e12)){
            puts("impossible");
            continue;
        }
        if(!ck)finde(0, n);
        if(!ck) puts("impossible");
        else {
            len = ans.size();
            reverse(ans.begin(), ans.end());
            for(i=0, ck=0; i<len; i++){
                if(ck) printf("+");
                printf("%d!", ans[i]);
                ck=1;
            }
            puts("");

        }
    }
    cout<<clock()<<endl;
    return 0;
}
