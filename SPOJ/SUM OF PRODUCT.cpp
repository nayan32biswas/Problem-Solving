#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define mod 1000000007
map< int, ull > store;
ull SerSum(ull lo, ull hi){
    return ((((hi*(hi+1))>>1)-((lo*(lo+1))>>1))%mod);
}
int Search(int End, int n, int mult){
    int Start=1, mid, x;
    while(Start<End){
        mid=(Start+End)>>1;
        x = n/mid;
        if(x<mult) Start=mid+1;
        else if(x>mult)End = mid-1;
    }
    return mid;
}
ull one(int n){
    int lo, End, i;
    ull sum;
    sum = (SerSum(1+(n>>1),n)+n)%mod;
    End = n>>1;
    while(End>1){
        i = n/End;
        lo = Search(End, n, i);
        lo = max(lo, 1);
        while((n/lo)>i) lo++;
        sum = (sum+SerSum(lo, End)*i)%mod;
        End=lo-1;
    }
    return sum;
}
ull two(int n){
    int lo, End, i;
    ull sum=0;
    End = sqrt(n);
    for(i=1; i<=End; i++){
        if(n/(i+1)>=End)sum = (sum+(SerSum(n/(i+1), n/i)*i))%mod;
        sum = (sum+((n/i)*i))%mod;
    }
    return sum%mod;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, test, n;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d", &n);
        printf("%llu\n", two(n));
    }
    return 0;
}
