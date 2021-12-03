#include <iostream>
#include <cstdio>
using namespace std;

inline long long FF(int *x, int l, int r) {
    long long sum=x[l];
    for(l++; l<=r; sum=sum | x[l], l++);
    return sum;
}

int main()
{
    int a[1009], b[1009], n, l, r;
    scanf("%d", &n);
    for(l=0; l<n; l++) scanf("%d", &a[l]);
    for(l=0; l<n; l++) scanf("%d", &b[l]);

    long long sum1=0, sum2=0;
    for(l=0; l<n; l++) {
        for(r=l; r<n; r++) {
            sum1 = max(sum1, FF(a, l, r));
            sum2 = max(sum2, FF(b, l, r));
        }
    }
    printf("%lld\n", sum1+sum2);
}
