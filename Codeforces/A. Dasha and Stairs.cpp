#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a, b;
    cin>>a>>b;
    if((a+1==b || b+1==a || a==b) && (a || b))puts("YES");
    else puts("NO");
    return 0;
}
