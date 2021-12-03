#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define LMT 1000040
using namespace std;
int prime[78888], jump[78888], arr[120];
bool pri[LMT+5], ck;

void seive() {
    int i, J, k, root=(int)(sqrt(LMT)+2);
    for(i=3; i<root; i+=2)if(!pri[i]) {
        for(J=i*i; J<LMT; J+=(i<<1)) pri[J]=1;
    }
    int temp=0, many;
    for(prime[0]=2, i=3, J=1, k=0; i<LMT; i+=2)if(!pri[i]) {
        jump[k]=i-prime[k];
        prime[J++]=i;
        k++;
    }
}
int binary(int key) {
    int mid, start=0, End=78500;
    while(start<=End) {
        mid = (start+End)/2;
        if(prime[mid]==key)return mid;
        else if(prime[mid]>key) End = mid-1;
        else start = mid+1;
    }
    return mid;
}
int main() {
    //freopen("input.txt", "r", stdin);
    seive();
    int L, U, test, ans, i;
    cin>>test;
    for(int t=1; t<=test; t++) {
        memset(arr, 0, sizeof(arr));
        scanf("%d%d", &L, &U);
        if(L<3) L = 2;
        else {
            if(!(L&1)) L++;
            while(1){
                if(!pri[L])break;
                L+=2;
            }
        }
        if(U<3) U = 2;
        else {
            if(!(U&1))U--;
            for(; U>0; U-=2){
                if(!pri[U])break;
            }
        }
        int lo, hi, coun, many, num;
        lo = binary(L);
        hi = binary(U);

        for(ans=0, many=0; lo<hi; lo++) {
            num = jump[lo];
            if(++arr[num]>many){
                many = arr[num];
                ans = num;
            }
        }

        for(i=1, coun=0, ck=true; i<115; i++){
            if(arr[i]==many){
                coun++;
                if(coun==2){
                    printf("No jumping champion\n");
                    ck = false;
                    break;
                }
            }
        }
        if(ck) {
            printf("The jumping champion is %d\n", ans);
        }
    }
    return 0;
}
