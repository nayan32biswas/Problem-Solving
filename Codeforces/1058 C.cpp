#include <bits/stdc++.h>
using namespace std;
string str;
int len;
int main()
{
    int n;
    bool check;
    cin>>len>>str;
    for(len--; str[len]=='0' && len>=0; len--);
    len++;
    for(int i=0; i<len; i++) str[i]-='0';
    n = 0;
    if(!len){
        puts("YES");
        return 0;
    }
    for(int i=0, j; i<len-1; i++){
        n += str[i];
        int x = 0;
        check = true;
        for(j=i+1; j<len; j++){
            if(x<n) x += str[j];
            else if(x==n){
                x = str[j];
            }
            else if(x>n){
                check = false;
                break;
            }
        }
        if(check && x==n){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
