#include <bits/stdc++.h>
using namespace std;
int main()
{
    string c;
    getline(cin, c);
    int len = c.size();
    bool b = false;
    for(int i=0; i<len; i++){
        if(c[i]=='H' || c[i]=='Q' || c[i]=='9'){
            b = true;
            break;
        }
    }
    if(b==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
