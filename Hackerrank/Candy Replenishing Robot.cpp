#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, arr[110], ans=0;
    cin>>n>>t;
    for(int i=0; i<t; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0, sum=n; i<t; i++){
        if(sum<5){
            ans+=abs(n-sum);
            sum=n;
        }
        sum-=arr[i];
    }
    cout<<ans<<endl;
    return 0;
}
