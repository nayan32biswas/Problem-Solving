#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, head, leg, hen, cow;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d", &cow, &leg);
        for(hen=0; cow>=0; cow--, leg-=2, hen++){
            if(cow==(leg>>2)) break;
        }
        printf("Case %d: %d %d\n", t, hen, cow);
    }
    return 0;
}
