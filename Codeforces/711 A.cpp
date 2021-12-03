#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    string s[1009];
    bool ck=false;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>s[i];
        if(!ck){
            if(s[i][0]=='O' && s[i][1]=='O') {
                s[i][0]='+', s[i][1]='+';
                ck = true;
            }
            else if(s[i][3]=='O' && s[i][4]=='O') {
                s[i][3]='+', s[i][4]='+';
                ck = true;
            }
        }
    }
    if(!ck) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++) {
            cout<<s[i]<<endl;
        }
    }
    return 0;
}
