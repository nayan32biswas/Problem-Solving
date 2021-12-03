#include <bits/stdc++.h>
using namespace std;
int len;
string str;
bool hydro() {
    string hydro = "hydro";
    if(len<5)
        return false;
    for(int i=0; i<len && i<5; i++)
        if(str[i]!=hydro[i])
            return false;
    return true;
}
bool ic() {
    string ic = "ic";
    if(len<2)
        return false;
    for(int i=len-1, j=1; i>=0 && j>=0; i--, j--)
        if(str[i]!=ic[j])
            return false;
    return true;
}
int main() {
    int test;
    cin>>test;
    while(test--) {
        cin>>str;
        len = str.size();
        if(hydro() && ic())
            puts("non-metal acid");
        else if(ic())
            puts("polyatomic acid");
        else
            puts("not an acid");
    }
    return 0;
}
