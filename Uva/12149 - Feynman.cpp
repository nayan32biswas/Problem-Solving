#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    unsigned long long a, arr[109], sum;
    int n, i;
    for(a=1, sum=0; a<105; a++){
        sum += a*a;
        arr[a] = sum;
    }
    while(scanf("%d", &n)==1 && n) {
        printf("%lld\n", arr[n]);
    }
    return 0;
}
