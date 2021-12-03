#include <bits/stdc++.h>
using namespace std;
#define Size 200005
long long arr[Size];
bool mark[Size];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    n--;
    for(int i=0; i<n; i++){
        if(arr[i+1]<=(arr[i]*2)){
            mark[i] = true;
        }
    }
    n++;
    int ans = 0, coun=0;
    for(int i=0; i<n; i++){
        if(mark[i]==false){
            coun = 0;
            //cout<<arr[i]<<endl;
        }
        else{
            //cout<<arr[i]<<" ";
            coun++;
        }
        ans = max(ans, coun);
    }
    cout<<ans+1<<endl;
    return 0;
}
