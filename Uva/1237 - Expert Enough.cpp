#include <bits/stdc++.h>
using namespace std;
typedef pair< pair<int, int>, string > ppi;
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    while(test--){
        int q;
        cin>>q;
        vector< ppi >data(q);
        for(int i=0; i<q; i++){
            cin>>data[i].second;
            scanf("%d", &data[i].first.first);
            scanf("%d", &data[i].first.second);
        }
        cin>>q;
        while(q--){
            int P;
            string ans;
            bool ck = false;

            scanf("%d", &P);
            for(auto a : data){
                if(a.first.first<=P && a.first.second>=P){
                    if(ck){
                        ck = false;
                        break;
                    }
                    ck = true;
                    ans = a.second;
                }
            }
            if(ck) cout<<ans<<endl;
            else puts("UNDETERMINED");
        }

        if(test) puts("");
    }

    return 0;
}
