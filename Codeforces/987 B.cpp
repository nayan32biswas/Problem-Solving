#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int main()
{
    long long x, y;
    cin>>x>>y;
    if(x==2 && y==3 || x==3 && y==2){
        if(x==2){
            puts("<");
        }
        else{
            puts(">");
        }
        return 0;
    }
    if(x==y || (x==2 && y==4) || (x==4 && y==2)){
        return puts("="), 0;
    }
    if(x==1){
        return puts("<"), 0;
    }
    if(y==1){
        return puts(">"), 0;
    }
    if(x<y){
        return puts(">"), 0;
    }
    else{
        return puts("<"), 0;
    }
}

