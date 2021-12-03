#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int k;
    cin>>k;
    while(k){
        if(k&1) str+='4', k--;
        else str += '8', k-=2;
        if(str.size()>18) {
            puts("-1");
            return 0;
        }
    }
    cout<<str<<endl;
    return 0;
}
