#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s, v1, v2, t1, t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int x=t1*2 + s*v1;
    int y = t2*2 + s*v2;
    if(x==y) puts("Friendship");
    else if(x>y) puts("Second");
    else puts("First");
}
