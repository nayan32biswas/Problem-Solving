#include <bits/stdc++.h>
using namespace std;
int call(string str){
    for(int i=0; i<str.size(); i++) if(str[i]=='.'){
        str[i] = '0';
    }
    cout<<str<<endl;
    return 0;
}
int main(){
    string str;
    int n, p;
    bool ans = false;
    cin>>n>>p>>str;
    for(int i=0; i+p<str.size(); i++){
        if(str[i]=='.'){
            if(str[i+p]=='.' || str[i+p]=='0') str[i] = '1';
            else str[i] = '0';
            return call(str);
        }
        else if(str[i+p]=='.'){
            if(str[i]=='.' || str[i]=='0') str[i+p] = '1';
            else str[i+p] = '0';
            return call(str);
        }
        else if(str[i] != str[i+p])return call(str);
    }
    puts("No");
    return 0;
}
