#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string str;
    cin>>n>>str;
    if(n==1 && str[0]=='0'){
        return puts("No"), 0;
    }
    for(int i=0; i<n-1; i++){
        if(str[i]=='1' && str[i+1]=='1'){
            return puts("No"), 0;
        }
        if(str[i]=='0' && str[i+1]=='0' && str[i+2]=='0'){
            return puts("No"), 0;
        }
    }
    if(str[n-1]=='0' && str[n-2]=='0' || str[0]=='0' && str[1]=='0'){
        return puts("No"), 0;
    }
    puts("Yes");
    return 0;
}
