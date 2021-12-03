#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s[120];
    char c;
    bool b;
    int n, MIN=100, len;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
        len = s[i].size();
        if(len<MIN) MIN=len;
    }
    for(int i=0; i<MIN; i++){
        c = s[0][i];
        b = true;
        for(int j=0; j<n; j++){
            if(c != s[j][i]) {b=false; break;}
        }
        if(b==true) cout<<c;
        //else break;

    }
    cout<<endl;
    return 0;
}
