#include <bits/stdc++.h>
using namespace std;
int arr[1000009];
int  main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, j, n;
    bool ck;
    cin>>test;
    while(test--) {
        scanf("%d", &n);
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        n--;
        while(true) {
            ck = false;
            for(j=0; j<n; j++) {
                if(arr[j]==(arr[j+1]+1)){
                    swap(arr[j], arr[j+1]);
                    ck=true;
                }
            }
            if(!ck) break;
        }
        for(ck=true, i=0; i<n; i++) {
            if(arr[i]>arr[i+1]){
                puts("No");
                ck = false;
                break;
            }
        }
        if(ck) puts("Yes");
    }

    return 0;
}
