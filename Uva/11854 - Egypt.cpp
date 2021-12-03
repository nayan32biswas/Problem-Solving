#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int a, b, c, Max;
    while(cin>>a>>b>>c && a && b && c) {
        a*=a;
        b*=b;
        c*=c;
        if(a==(b+c) || b==(a+c) || c==(b+a)){
            puts("right");
        }
        else puts("wrong");
    }
    return 0;
}
