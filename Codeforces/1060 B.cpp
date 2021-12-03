#include <stdio.h>
long long n, a;
main() {
    scanf("%lld", &n);
    while(n>=9) {
        a += 9+(n-9)%10;
        n=(n-9)/10;
    }
    printf("%lld", n+a);
}
