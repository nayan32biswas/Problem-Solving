#include <bits/stdc++.h>
using namespace std;
vector<int>v, v1;
string s;
int len;
int to_int(int i, int J)
{
    if(s[i]=='0') return 0;
    int ans = 0, temp, k=0;
    for(k=0; i<=J; i++){
        ans=(ans*10)+(s[i]-48);
    }
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test, i, lenv, J, temp, k;
    cin>>test;
    bool ck;
    for(int t=1; t<=test; t++){
        cin>>s;
        cout<<'\t'<<s<<endl;
        len = s.size(); ck = false;
        if(len<2){puts("NO");continue;}

        for(i=1; i<len; i++)
            if(s[i-1]+1!=s[i]) break;

        cout<<'\t'<<i<<endl;
        if(i==len){
            printf("YES %c\n", s[0]);continue;
        }
        if(s[0]=='0'){puts("NO");continue;}

        for(i=1; i<=(len>>1); i++){
            for(J=i, v.clear(); J<=len; J+=i){
                temp = to_int(J-i, J-1);
                v.push_back(temp);
            }
            for(J=i, v1.clear(); J<=len; J+=i){
                temp = to_int(J-i, J);
                v1.push_back(temp);
            }

            for(J=0, lenv = v.size(); J<lenv; J++){
                cout<<v[J]<<' ';
            }puts("");

            for(J=0, lenv = v1.size(); J<lenv; J++){
                cout<<v1[J]<<' ';
            }puts("\n");
        }
        puts("\n");
    }

    return 0;
}
