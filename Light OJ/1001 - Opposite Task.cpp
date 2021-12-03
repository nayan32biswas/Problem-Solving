#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test, a, b, n, i, j;
    scanf("%d",&test);
    while(test--){
        scanf("%d", &n);
        if(n>10)printf("10 %d\n", n-10);
        else printf("%d 0\n", n);
    }
    return 0;
}
