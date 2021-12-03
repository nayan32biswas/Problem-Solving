#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a, b, c, test;
    double ans;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d%d",&a,&b,&c);
        ans = (a*100);
        if(ans<(c*b)) printf("Case %d: NO\n", t);
        else  printf("Case %d: YES\n", t);
    }
    return 0;
}
