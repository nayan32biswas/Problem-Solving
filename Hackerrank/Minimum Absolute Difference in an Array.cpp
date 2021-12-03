#include <bits/stdc++.h>
using namespace std;
int arr[100009];
int main(){
    //freopen("input.txt", "r", stdin);
    int n, a, b;
    long long ans = 99999999999999999;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >>arr[i];
    }
    sort(arr, arr+n);
    for(int i=1; i<n; i++){
        b = abs(arr[i-1]-arr[i]);
        if(b<ans) ans = b;
        if(ans == 0) break;
    }
    cout<<ans<<endl;
    return 0;
}
