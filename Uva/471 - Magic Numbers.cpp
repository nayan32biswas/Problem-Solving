#include <bits/stdc++.h>
using namespace std;
bool mark[10];
int x;
bool check(long long n){
    memset(mark, 0, sizeof(mark));
    while(n){
        x = n%10;
        if(mark[x])return false;
        mark[x] = 1;
        n /= 10;
    }
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    long long N, temp;
    scanf("%d", &test);
    for(int t=0; t<test; t++){
        scanf("%lld", &N);
        if(t) puts("");
        int coun = 0;
        for(int i=1; ; i++)if(check(i)){
            temp = N*i;

            if(temp>9999999999LL) break;
            if(check(temp)){
                printf("%lld / %d = %lld\n", temp, i, N);
            }
        }
    }
    return 0;
}
