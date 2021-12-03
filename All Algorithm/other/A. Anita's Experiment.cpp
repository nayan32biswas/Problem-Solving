#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int arr[1004], test, N, i, j, good, bad, none, special;
    cin>>test;
    while(test--){
        scanf("%d", &N);
        good = bad = none = special = 0;
        for(i=0; i<N; i++) scanf("%d", &arr[i]);

        for(i=1; i<N; i++){
            if((i<(N-1)) && (arr[i-1]<arr[i] && arr[i]>arr[i+1])) special++;
            else if(arr[i-1]==arr[i]) none++;
            else if(arr[i-1]<arr[i]) good++;
            else bad++;
        }
        if(special) printf("%d\n", special);
        else if(bad==0) puts("allGoodDays");
        else if(good==0) puts("allBadDays");
        else if(bad==good) puts("none");
        else puts("none");
        printf("%d %d %d %d\n", special, good, bad, none);
    }
    return 0;
}
