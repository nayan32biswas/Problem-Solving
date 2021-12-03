#include <bits/stdc++.h>
using namespace std;
bool polin(string s) {
    int len=s.size();
    int i, j, many=0;
    for(i=0, j=len-1; (i<(len/2)); i++, j--){
        if(s[i]!=s[j]){
            many++;
        }
    }
    if(many==1) return true;
    if(many==0){
        if(len&1) return true;
        return false;
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    if(polin(s)==true) puts("YES");
    else puts("NO");
}
