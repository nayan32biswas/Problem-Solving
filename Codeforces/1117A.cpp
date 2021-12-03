#include <bits/stdc++.h>
using namespace std;
#define Size 100005
int arr[Size];
int main()
{
    int n, Max=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        Max = max(arr[i], Max);
    }
    int ans=0, temp=0;
    for(int i=0; i<n; i++){
        if(arr[i]==Max){
            temp++;
        }
        else{
            ans = max(temp, ans);
            temp = 0;
        }
    }
    printf("%d\n", ans = max(temp, ans));
    return 0;
}