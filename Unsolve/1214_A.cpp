#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
lli dolor[] = {1, 2, 5, 10, 20, 50, 100};
lli euro[] = {5, 10, 20, 50, 100, 200};
vector<lli> ammount;
int last;
lli sum(lli num, int pos){
    if(num<0 or pos>13)
        return INT_MAX;
    lli ans=INT_MAX;
    for (int i=pos; i<last; i++){
        if(num>=ammount[i]){
            // cout<<num<<" "<<ammount[i]<<endl;
            ans = min(sum(num-ammount[i], i), ans);
        }
    }
    return min(ans, num);
}

lli solve()
{
    lli n, d, e;
    last = 13;
    scanf("%lld%lld%lld", &n, &d, &e);
    for (int i = 0; i < 7; i++)
        ammount.push_back(dolor[i] * d);
    for (int i = 0; i < 6; i++)
        ammount.push_back(euro[i] * e);
    sort(ammount.begin(), ammount.end(), greater<int>());
    
    return sum(n, 0);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    printf("%lld\n", solve());
    return 0;
}