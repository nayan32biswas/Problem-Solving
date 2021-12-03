#include <bits/stdc++.h>
using namespace std;
int arr[1000];
string s;
int main()
{
    int n, zero=0;
    cin>>s;
    int i=0;
    for(i=0; s[i]; i++) if(s[i]=='1') break;
    for(; s[i]; i++) if(s[i]=='0') zero++;
    if(zero>=6) puts("yes");
    else puts("no");

    return 0;
}
