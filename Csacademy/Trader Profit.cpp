#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
long long ans;
map<ppi, bool>M;
int n, arr[50];
void call(int now, int next){
    if(now>=n || next>=n) return;
    for(i=now; i<n-1; i++){
        if(arr[i]<arr[i+1] && M[make_pair(i+1, i)]==false){
            M[make_pair(i+1, i)] = 1;
            ans.push_back(arr[i+1]-arr[i]);
        }
    }
}
int main()
{
    int i, x, k, test;
    cin>>test;
    while(test--){
        scanf("%d%d", &n, &k);
        ans = 0;
        M.clear();
        memset(arr, 0, sizeof(arr));
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        call(0, 1);
        sort(ans.begin(), ans.end());
        for(i=ans.size()-1, x=0; i>=0 && k>0; i--, k--){
            x+=ans[i];
        }
        cout<<x<<endl;
    }
    return 0;
}
