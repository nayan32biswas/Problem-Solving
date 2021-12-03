#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int sum;
    sum=(s[0]-48)*10;
    sum+=(s[1]-48);
    if(sum==12 && s[8]=='P'){
        cout<<"12";
        for(int i=2; i<s.size()-2; i++)
            cout<<s[i];
        cout<<endl;
    }
    else if(s[8]=='A' && sum!=12){
        for(int i=0; i<s.size()-2; i++)
            cout<<s[i];
        cout<<endl;
    }

    else {
        sum+=12;
        if(sum==24)cout<<"00";
        else cout<<sum;
        for(int i=2; i<s.size()-2; i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}
