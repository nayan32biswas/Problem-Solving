#include <cstdio>
#include <cmath>
#define LMT 1000000
///#define GET(x) (mark[x>>5]>>(x&31)&1)
///#define SET(x) (mark[x>>5]|=1<<(x&31))
using namespace std;
bool pri[LMT], ck;
int prime[88888];

void seive()
{
    int i, J, root=sqrt(LMT)+2;
    for(pri[1]=1, i=3; i<root; i+=2)if(!pri[i]){
        for(J=i*i; J<LMT; J+=(i<<1))pri[J]=1;
    }
    for(prime[0]=2, i=3, J=1; i<LMT; i+=2)if(!pri[i]){
        prime[J++]=i;
    }
}
inline bool big_prime(int num)
{
    if(num<LMT) return !pri[num];
    int i, root=sqrt(num)+2;
    for(i=1; prime[i]<root; i++)if(num%prime[i]==0){
        return false;
    }
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    seive();
    long long i, L, U;
    int past, p1, p2, p3, p4, Min, Max, J;
    while(scanf("%lld%lld", &L, &U)==2){
        past = -1;
        ck = false;
        Min = 99999, Max = -Min;
        if(U<3){
            puts("There are no adjacent primes.");
            continue;
        }
        if(L<3){
            p1=2, p2 = 3;
            p3=2, p4 = 3;
            Max = 1, Min=1;
            L = 3;
            ck = true;
            /// this is special condition for (2);
        }
        for(; L<U; L++)if((L&1) && big_prime(L))break;
        /// this loop for find first prime;
        for(i=L, U++; i<U; i+=2) {
            /// here i skip all even number;
            if(big_prime(i)) {
                if(past == -1) past = i;
                else {
                    J=i-past;
                    if(J<Min) {
                        Min = J;
                        p1 = past, p2 = i;
                    }
                    if(J > Max) {
                        Max = J;
                        p3 = past, p4 = i;
                    }
                    past = i;
                    ck = true;
                }
            }
        }
        if(!ck)
            puts("There are no adjacent primes.");
        else {
            printf("%d,%d are closest, ", p1, p2);
            printf("%d,%d are most distant.\n", p3, p4);
        }
    }
    return 0;
}
