#include <bits/stdc++.h>
using namespace std;
#define Size 200005
int arr[Size], temp[Size];
int mark[Size*10];
void MARK(int lo, int hi){
    if(lo>hi)swap(lo, hi);
    lo = max(lo, 0);

    for(; lo<=hi; lo++){
        if(mark[lo]){
            lo = mark[lo];
        }
        else{
            mark[lo] = hi;
        }
    }
}
int main()
{
    int n, k, x;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n, greater<int>());
    for(int i=0; i<n; i++){
        x = arr[i];
        MARK(x-k, x-1);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(!mark[arr[i]])ans++;
    }
    printf("%d\n", ans);
    return 0;
}

