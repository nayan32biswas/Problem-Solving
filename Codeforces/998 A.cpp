#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main() {
    int n, ans, Min = INT_MAX;
    cin>>n;
    if(n==1)return puts("-1"), 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]<Min){
            ans = i+1;
            Min = arr[i];
        }
    }
    if(n==2 && arr[0]==arr[1]){
        return puts("-1"), 0;
    }
    printf("1\n%d", ans);
    return 0;
}
