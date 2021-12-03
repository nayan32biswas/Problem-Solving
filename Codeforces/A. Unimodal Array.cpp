#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, n, num, num1, arr[109];
    scanf("%d", &n);
    if(n==1) return puts("YES"), 0;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    if(arr[0]==arr[1]){
        i=0;
        while(i<n-1 && arr[i]==arr[i+1]) i++;
        for(; i<n-1; i++) if(arr[i]<=arr[i+1]) return puts("NO"), 0;
        return puts("YES"), 0;
    }
    for(i=0; i<n-1; i++)if(arr[i]>=arr[i+1]) { break; }
    while(i<n-1 && arr[i]==arr[i+1]) i++;
    for(; i<n-1; i++){
        if(arr[i]<=arr[i+1]) return puts("NO"), 0;
    }
    return puts("YES"), 0;
}
