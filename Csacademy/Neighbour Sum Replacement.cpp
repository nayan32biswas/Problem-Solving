#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1009], ans[1009], n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    ans[0] = arr[1]+arr[n-1];
    ans[n-1] = arr[0]+arr[n-2];
    for(int i=1; i<n-1; i++){
        ans[i] = arr[i-1]+arr[i+1];
    }
    cout<<n<<endl;
    for(int i=0; i<n; i++){
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}
