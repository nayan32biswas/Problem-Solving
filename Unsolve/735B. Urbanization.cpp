#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int main()
{
    int n, a, b, i, tempa, tempb;
    double ans, city1=0, city2=0;
    cin>>n>>a>>b;
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr+n);
    if(a>b) swap(a,b);
    tempa = a;
    tempb = b;
    for(i=n-1; tempa>0; i--){
        city1+=arr[i];
        tempa--;
    }
    n-=a;
    for(i=n-1; tempb>0; i--){
        city2+=arr[i];
        tempb--;
    }
    ans = (city1/a)+(city2/b);
    cout<<fixed<<setprecision(8)<<ans<<endl;
    return 0;
}
