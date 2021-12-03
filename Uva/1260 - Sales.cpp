#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main()
{
    int test, N, ans;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf("%d", &arr[i]);
        }
        ans = 0;
        for(int i=1; i<N; i++){
            for(int j=i-1, x=arr[i]; j>=0; j--){
                if(arr[j]<=x) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
