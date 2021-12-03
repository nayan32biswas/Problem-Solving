#include <bits/stdc++.h>
using namespace std;
string s="..O..", s1="O.o.O";
int main()
{
    int r, c, i;
    cin>>r>>c;
    while(r--) {
        for(i=0; i<c; i++)cout<<s;
        puts("");
        for(i=0; i<c; i++)cout<<s1;
        puts("");
        for(i=0; i<c; i++)cout<<s;
        puts("");
    }
    return 0;
}
