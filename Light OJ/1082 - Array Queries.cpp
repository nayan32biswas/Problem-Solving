#include <bits/stdc++.h>
using namespace std;
#define Size 100100
int arr[Size];
int Sqrt[Size];
int SQ, n;
int Min(int lo, int hi){
    int num = INT_MAX, i;
    if(hi-lo<10){
        for(; lo<=hi; lo++) num = min(arr[lo], num);
        return num;
    }

    for(i=hi; i>=lo; i--){
        num = min(arr[i], num);
        if(i%SQ==0) break;
    }
    for(i=lo; i<hi; i++){
        num = min(arr[i], num);
        if((i+1)%SQ==0) break;
    }
    for(hi = hi/SQ, i=(lo/SQ)+1; i<hi; i++) num = min(Sqrt[i], num);
    return num;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, q, num, i, j, lo, hi;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d", &n, &q);
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        if(n>8){
            SQ = ceil(sqrt(n));
            for(i=0, num=INT_MAX; i<n; i++){
                num = min(num, arr[i]);
                if((i+1)%SQ==0){
                    Sqrt[i/SQ] = num;
                    num = INT_MAX;
                }
            }
            Sqrt[i/SQ]=num;
        }
        printf("Case %d:\n", t);
        while(q--){
            scanf("%d%d", &lo, &hi);
            printf("%d\n", Min(--lo, --hi));
        }
    }
}
