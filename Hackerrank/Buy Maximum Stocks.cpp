#include<bits/stdc++.h>
using namespace std;
struct data{
    int x, pos;
}arr[100009];
bool cmp(data a, data b){
    if(a.x!=b.x) return a.x<b.x;
    return a.pos>b.pos;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i;
    long long k, x, ans;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &arr[i].x), arr[i].pos=i+1;
    cin>>k;
    sort(arr, arr+n, cmp);
    for(i=0, ans=0; i<n; i++){
        x = arr[i].pos*arr[i].x;
        if((k-x)>0){
            k-=x;
            ans+=arr[i].pos;
        }
        else {
            x = arr[i].x;
            n = arr[i].pos;
            for(i=0; i<n; i++){
                k-=x;
                if(k<0) break;
                ans++;
            }
            break;
        }
    }
    printf("%lld\n", ans);
}
