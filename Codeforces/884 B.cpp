#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main()
{
    int n, x, ai, i;
    long long ans = 0;
    cin>>n>>x;
    for(i=0; i<n; i++){
        scanf("%d", &ai);
        ans+=ai;
    }
    if(ans==(x-(n-1))) puts("YES");
    else puts("NO");
    return 0;
}

