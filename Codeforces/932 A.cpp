#include <bits/stdc++.h>
using namespace std;
#define Size 10000
int main(){
    string str, s;
    cin>>str;
    s = str;
    reverse(str.begin(), str.end());
    cout<<s+str<<endl;
    return 0;
}
