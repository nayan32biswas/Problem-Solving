#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, x, now;
    cin>>n>>x;
    now=x%6;
    if(now==0) cout<<x<<endl;
    else if(now==1){
        if(x==1)puts("0");
        else if(x==0)puts("1");
        else puts("2");
    }
    else if(now==2){
        if(x==0)puts("2");
        else if(x==1)puts("0");
        else puts("1");
    }
    else if(now==3){
        if(x==0)puts("2");
        else if(x==1)puts("1");
        else puts("0");
    }

    else if(now==4){
        if(x==0)puts("1");
        else if(x==1)puts("2");
        else puts("0");
    }
    else if(now==5){
        if(x==0)puts("0");
        else if(x==1)puts("2");
        else puts("1");
    }
    return 0;
}
