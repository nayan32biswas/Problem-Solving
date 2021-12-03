#include <bits/stdc++.h>
typedef long long int lli;
lli N;
int main(){
    while(scanf("%lld", &N) && N>=0){
        printf("%lld\n", (N*(N+1)/2)+1);
    }
    return 0;
}
