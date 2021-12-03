#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main()
{
    int n, m, l, r;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>l>>r;
        arr[l]++;
        arr[r+1]--;
    }
    vector<int>ans;
    for(int i=1; i<=m; i++){
        arr[i] += arr[i-1];
        if(arr[i]==0){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it : ans)cout<<it<<" "; puts("");
    return 0;
}
