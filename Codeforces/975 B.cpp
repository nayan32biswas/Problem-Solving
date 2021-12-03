#include <bits/stdc++.h>
using namespace std;
long long arr[14], hole[14];
long long Find(int pos) {
    if(arr[pos]==0) {
        return 0;
    }
    long long ans=0;
    int x = arr[pos];
    arr[pos] = 0;
    for(int i=pos+1; i<14 && x>0; i++, x--) {
        arr[i]++;
    }
    int every = x/14;
    x %= 14;
    for(int i=0; i<x; i++) {
        arr[i]++;
    }
    for(int i=0; i<14; i++) {
        arr[i]+= every;
        if(arr[i]%2==0) {
            ans += arr[i];
        }
    }
    //for(int i=0; i<14; i++) cout<<arr[i]<<" "; puts("");
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int x;
    for(int i=0; i<14; i++) {
        cin>>hole[i];
    }
    long long ans = 0;
    for(int i=0; i<14; i++) {
        for(int j=0; j<14; j++) {
            arr[j] = hole[j];
        }
        ans = max(ans, Find(i));
    }
    cout<<ans<<endl;
    return 0;
}
