#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int main()
{
    cin>>n>>str;
    for(int i=1; i<n; i++){
        if(str[i]==str[i-1] && str[i]!='?'){
            puts("No");
            return 0;
        }
    }
    if(str[0]=='?' || str[n-1]=='?'){
        puts("Yes");
        return 0;
    }
    for(int i=0; i<n; i++){
        if(str[i]=='?'){
            int s = i;
            while(str[i]=='?'){
                i++;
            }
            if(str[s-1]==str[i] || (i-s)>1){
                puts("Yes");
                return 0;
            }
            i--;
        }
    }
    puts("No");
    return 0;
}
/*
5
M?C?Y
*/
