#include <bits/stdc++.h>
using namespace std;
long double temp, A, B;
long long x, y, l, r, ans, arr[1000000];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>x>>y>>l>>r;
    int n = 0, i;
    for(A=1; A<=r; A*=x){
        if(A<=r && A>=l) arr[n++]=(long long)A;
    }
    for(B=1; B<=r; B*=y){
        if(B<=r && B>=l){
            arr[n++]=(long long)B;
        }
    }
    for(A=1; A<=r; A*=x){
        for(B=1; (A+B)<=r; B*=y){
            temp = A+B;
            if(temp<=r && temp>=l){
                arr[n++]=(long long)temp;
            }
        }
    }
    bool ck=false;
    //for(i=0; i<n; i++) cout<<arr[i]<<' ';cout<<endl;
    sort(arr, arr+n);
    ans = max(r-arr[n-1], arr[0]-l);
    if(n==0) ans = r-l+1;
    for(i=0, n--; i<n; i++)if(arr[i]>=l){
        ans = max(ans, (arr[i+1]-arr[i]-1));
        ck=true;
    }
    cout<<ans<<endl;
}
/// 2 14 732028847861235712 732028847861235712
/// 14 2 732028847861235713 732028847861235713
