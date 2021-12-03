#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main()
{
    int n, k, x;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        scanf("%d", &x);

        if(arr[x]==0){
            arr[x] = i;
        }
    }
    vector<int>ans;
    for(int i=1; i<=100; i++){
        if(arr[i]>0){
            ans.push_back(arr[i]);
        }
    }
    if(ans.size()<k){
        puts("NO");
    }
    else{
        puts("YES");
        for(int i=0; i<k; i++){
            if(i) printf(" ");
            cout<<ans[i];
        }
        puts("");
    }

    return 0;
}
