#include <bits/stdc++.h>
using namespace std;
int TF, two, one, other;
int arr[105];
bool cmp(int a, int b){return a>b;}
int main()
{
    int len, i, j, n, k, x, ans;
    cin>>n>>k;
    for(i=0, j=0; i<k; i++){
        scanf("%d", &x);
        while(x>=7)x-=8, n--;
        else if(x==2)two++;
        else if(x==4 || x==3)TF++;
        else if(x>0) arr[j++]=x;
        if(two>1) TF++, two=0;
        if(TF>1)n--, TF=0;

    }k = j;
    sort(arr, arr+k, cmp);
    for(i=0, ans=2; i<k; i++){
        x = arr[i];
        while(x>0) {
            x--;
            ans++;
        }
        if(ans%4!=0) ans++;
    }
    ans-=2;
    if(n<0) return puts("NO"), 0;
    if(n==0 && ans>0) return puts("NO"), 0;

    n*=8;
    if(ans>n) puts("NO");
    else puts("YES");
    return 0;
}
