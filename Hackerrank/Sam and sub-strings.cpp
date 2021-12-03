#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
inline long long sub_sum(char *s, int lo, int hi) {
    long long ans=0;
    for(; lo<=hi; lo++){
        ans = (ans*10) + s[lo];
    }
    return ans;
}
int main()
{
    int i, J, len, lo, hi;
    long long ans=0, temp;
    char s[200005];
    scanf("%s", s);
    len = strlen(s);
    for(i=0; i<len; i++) s[i]-=48;
    for(i=0; i<len; i++) {
        for(J=i; J<len; J++) {
            ans += sub_sum(s, i, J);
            if(ans>MOD) ans %= MOD;
        }
    }
    printf("%d\n", ans%MOD);
    return 0;
}
