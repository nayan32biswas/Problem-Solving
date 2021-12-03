#include <bits/stdc++.h>
using namespace std;
int ans[129];
int main()
{
    int n, k, i;
    cin>>n>>k;
    string s;
    cin>>s;
    for(auto c : s) ans[c]++;
    for(i=97; i<123; i++) if(ans[i]>k) return puts("NO"), 0;
    puts("YES");
    return 0;
}
