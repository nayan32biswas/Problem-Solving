#include <bits/stdc++.h>
using namespace std;
#define Size 202
bool mark[Size];
int test, n, k;
int main() {

    cin>>test;
    while(test--) {
        cin>>n>>k;
        vector<int>KKK(k);
        vector< pair<int, int> >vis(k);
        memset(mark, 0, sizeof(mark));
        for(int i=0; i<k; i++) {
            cin>>KKK[i];
            mark[KKK[i]]=1;
            vis[i] = make_pair(KKK[i], KKK[i]);
            vis[i].first = max(1, vis[i].first-1);
            vis[i].second = min(n, vis[i].second+1);
        }
        int ans = 1;
        int End = n-k;
        while(End) {
            for(int i=0; i<k; i++) {
                if(mark[vis[i].first]==0) {
                    mark[vis[i].first] = 1;
                    End--;
                }
                if(mark[vis[i].second]==0) {
                    mark[vis[i].second] = 1;
                    End--;
                }
                vis[i].first = max(1, vis[i].first-1);
                vis[i].second = min(n, vis[i].second+1);
            }
            ans++;
        }
        cout<<ans<<endl;

    }
}
