#include <bits/stdc++.h>
using namespace std;
bool arr[105];
int main()
{
    int test, n, x;
    cin>>test;
    while(test--){
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));
        int ans = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &x);
            if(arr[x]) ans++;
            arr[x] = 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
