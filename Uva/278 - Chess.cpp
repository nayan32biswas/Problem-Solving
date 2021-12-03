#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int m, n, test, ans, board;
    char c;
    scanf("%d\n", &test);
    while(test--){
        scanf("%c%d%d\n", &c, &m, &n);
        if(c=='Q') ans = m>n ? n : m;
        else if(c=='r') ans = m>n ? n : m;
        else if(c=='K') ans = (((m+1)>>1) * ((n+1)>>1));
        else if(c=='k') ans = (((m+1)>>1) * ((n+1)>>1)) + ((m>>1) * (n>>1));
        printf("%d\n", ans);
    }
    return 0;
}
