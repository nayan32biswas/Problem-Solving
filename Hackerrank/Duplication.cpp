#include <bits/stdc++.h>
using namespace std;
string s="01101001";
int main()
{
    int i, test, x, len;
    test=11;
    while(test--){
        len = s.size();
        for(i=0; i<len; i++){
            if(s[i]=='0') s+='1';
            else s+='0';
        }
    }
    cin>>test;
    for(int t=0; t<test; t++){
        scanf("%d", &x);
        printf("%c\n", s[x]);
    }
    return 0;
}
