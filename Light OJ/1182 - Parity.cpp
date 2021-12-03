#include <bits/stdc++.h>
using namespace std;
int check(int n){
    int coun=0;
    while(n>0){
        if(n&1) coun++;
        n>>=1;
    }
    return coun;
}
int main()
{
    int test, n;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d", &n);
        printf("Case %d: ", t);
        if(check(n)&1) puts("odd");
        else puts("even");
    }
}
