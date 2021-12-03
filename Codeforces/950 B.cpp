#include <bits/stdc++.h>
using namespace std;
#define Size 100009
int arr[Size], arr1[Size];
int main()
{
    long long sum=0, sum1=0, ans = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<m; i++) scanf("%d", &arr1[i]);
    for(int i=0, j=0, k=0; k<(n+m); k++){
        if(sum<sum1){
            sum += arr[i++];
        }
        else {
            sum1 += arr1[j++];
        }
        if(sum==sum1){
            ans++;
            sum = sum1 = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
