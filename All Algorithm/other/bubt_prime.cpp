#include <bits/stdc++.h>
#define LMT 1000100
using namespace std;
int prime[7][70000], len[7];
unsigned pri[(LMT>>6)+5];
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
void seive() {
    int i, j, root = sqrt(LMT)+2;
    for(i=3, Set(1); i<root; i+=2)if(!Check(i)){
        for(j=(i*i); j<LMT; j+=(i<<1)) Set(j);
    }
    prime[1][0]=2;
    for(i=3, j=1; i<10; i+=2)if(!Check(i))prime[1][j++]=i;
    len[1] = --j;
    for(i=11, j=0; i<100; i+=2)if(!Check(i))prime[2][j++]=i;
    len[2] = --j;
    for(i=101, j=0; i<1000; i+=2)if(!Check(i))prime[3][j++]=i;
    len[3] = --j;
    for(i=1001, j=0; i<10000; i+=2)if(!Check(i))prime[4][j++]=i;
    len[4] = --j;
    for(i=10001, j=0; i<100000; i+=2)if(!Check(i))prime[5][j++]=i;
    len[5] = --j;
    for(i=100001, j=0; i<1000000; i+=2)if(!Check(i))prime[6][j++]=i;
    len[6] = --j;
    cout<<clock()<<endl;
}
int Binary_search(int n, int key) {
    int start=0, mid, End=len[n];
    while(start<=End) {
        mid = (start+End)/2;
        if(prime[n][mid]==key)return mid;
        else if(prime[n][mid]>key) End = mid-1;
        else start = mid+1;
    }
    return mid;
}
int main()
{
    freopen("input.txt", "r", stdin);
    seive();
    int test, n, digit, lo, hi, P, Q;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        scanf("%d%d%d", &digit, &P, &Q);
        lo = Binary_search(digit, P);
        if(prime[digit][lo]<P) lo++;
        hi = Binary_search(digit, Q);
        if(prime[digit][hi]>Q) hi--;
        printf("Case %d: %d\n", t, (hi-lo)+1);
    }
    return 0;
}
