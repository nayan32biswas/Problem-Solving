#include <bits/stdc++.h>
using namespace std;
int arr[40009];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, left, right, x, y, i, J, ans;
    cin>>n>>q;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    while(q--){
        scanf("%d%d%d%d", &left, &right, &x, &y);
        for(i=left, ans=0; i<=right; i++) {
            if(arr[i]%x==y)ans++;
        }
        cout<<ans<<endl;
    }
}
