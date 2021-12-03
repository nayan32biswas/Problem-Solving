#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ppi;
#define MAX INT_MAX
long long solve(){
    ppi Max = make_pair(-MAX, -MAX), Min = make_pair(MAX, MAX);
    int n;
    cin>>n;
    while(n--){
        long long x, y;
        for(int i=0; i<4; i++){
            cin>>x>>y;
            Min.first = min(Min.first, x);
            Min.second = min(Min.second, y);

            Max.first = max(Max.first, x);
            Max.second = max(Max.second, y);
        }
    }
    //printf("%lld %lld %lld %lld\n", Max.first, Min.first, Max.second, Min.second);
    return (Max.first-Min.first)*(Max.second-Min.second);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    while(test--){
        cout<<solve()<<endl;
    }
    return 0;
}
