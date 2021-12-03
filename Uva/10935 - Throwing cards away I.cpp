#include <bits/stdc++.h>
using namespace std;
bool ck[100];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i, len;
    vector<int>v, ans;
    while(scanf("%d", &n)==1 && n){
        if(n<4){
            if(n==1)printf("Discarded cards:\nRemaining card: 1\n");
            else if(n==2) printf("Discarded cards: 1\nRemaining card: 2\n");
            else printf("Discarded cards: 1, 3\nRemaining card: 2\n");
            continue;
        }
        v.clear();
        ans.clear();
        memset(ck, 0, sizeof(ck));
        for(i=1; i<=n; i+=2) ans.push_back(i);
        if(n&1){
            for(i=4; i<=n; i+=2)v.push_back(i);v.push_back(2);
        }
        else for(i=2; i<=n; i+=2)v.push_back(i);
        i=0;
        while(!ck[v[i]]){
            ans.push_back(v[i]);
            ck[v[i]]=1;
            v.push_back(v[i+1]);
            len = v.size()-1;
            if(len-i<3){
                ans.push_back(v[++i]);
                if(len==i) ans.push_back(v[i]);
                break;
            }
            i+=2;
        }
        printf("Discarded cards: ");
        for(i=0, len = ans.size(); i<len-1; i++){
            if(i) printf(", ", ans[i]);
            cout<<ans[i];
        }puts("");
        printf("Remaining card: %d\n", ans[i]);
    }
    return 0;
}
