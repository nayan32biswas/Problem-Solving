#include <bits/stdc++.h>
using namespace std;
#define Size 100005
int mark[Size];
long long arr[Size];
string str[Size];
map<string, int>MAP;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m, x, xi;
    scanf("%d%d%d", &n, &k, &m);
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<k; i++){
        scanf("%d", &x);
        long long Min = INT_MAX;
        for(int j=0; j<x; j++){
            scanf("%d", &mark[j]);
            mark[j]--;
            Min = min(Min, arr[mark[j]]);
            //cout<<arr[mark[j]]<<" ";
        }
        //cout<<Min<<endl;
        for(int j=0; j<x; j++){
            MAP[str[mark[j]]] = Min;
        }
    }
    //puts("");
    string temp;
    long long ans = 0;
    for(int i=0; i<m; i++){
        cin>>temp;
        ans += MAP[temp];
    }
    cout<<ans<<endl;
    return 0;
}
