#include <bits/stdc++.h>
using namespace std;
#define Size 100005
int arr[Size];
long long A;
int Find(int Si, int S) {
    return (A*Si)/S;
}
int main() {
    int n, B, F, ans=0, S=0, Si;
    cin>>n>>A>>B;
    cin>>Si;
    S = Si;
    n--;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        S += arr[i];
    }
    if(Find(Si, S)>=B) {
        puts("0");
        return 0;
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    for(int i=0; i<n; i++) {
        S -= arr[i];
        ans++;
        if(Find(Si, S)>=B) {
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
