#include <bits/stdc++.h>
using namespace std;
int n, mark[22];
vector<string>player;
void print(string s){for(auto c:s)printf("%d",c);puts("");}
string to_bit(int num){
    string s="";
    int i=0;
    while(num>0 && i<n) {
        if(num&1)s+=i;
        num>>=1;
        i++;
    }
    return s;
}
int differ(string a, string b){
    memset(mark, 0, sizeof(mark));
    int dif=0;
    for(auto c:a) mark[c]++;
    for(auto c:b) mark[c]++;
    for(int i=0; i<n; i++)if(mark[i]==1) dif++;
    return dif;
}
int main()
{
    int i, j, m, k, x, ans=0;
    cin>>n>>m>>k;
    for(i=0; i<m; i++){
        scanf("%d", &x);
        player.push_back(to_bit(x));
    }
    scanf("%d", &x);
    string he=to_bit(x);
    for(i=0; i<m; i++)if(differ(he, player[i])<=k)ans++;
    cout<<ans<<endl;
    return 0;
}
