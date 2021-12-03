#include <bits/stdc++.h>
using namespace std;
struct data
{
    char s[15];
    int len;
    bool operator <(const data& x)const{return len>x.len;}
}s1[100050];
map<string, bool>M;
int to_int(char x[], int line, int pos)
{
    int ans = 0;
    for(int i=0; i<line; i++) {
        ans += x[i];
    }
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i, J, line;
    long long ans;
    scanf("%d\n", &n);
    for(i=0; i<n; i++){
        scanf("%s", s1[i].s);
        s1[i].len = strlen(s1[i].s);
        M[s1[i].s]=1;
    }
    sort(s1, s1+n);
    for(i=0; i<n; i++){
        line = s1[i].len;
        //cout<<s1[i].s<<' '<<line<<endl;
        if(line>1){
            string temp="";
            for(J=0, line--; J<line; J++){
                temp = temp + s1[i].s[J];
                M[temp]=false;
            }
        }
    }
    for(i=0, ans=0; i<n; i++) {
        if(M[s1[i].s]==1){
            line = s1[i].len;
            ans += to_int(s1[i].s, line, i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
