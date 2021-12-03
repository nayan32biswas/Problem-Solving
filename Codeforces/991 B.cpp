#include <bits/stdc++.h>
using namespace std;
int arr[101], n;
void inc(){
    for(int i=0; i<n; i++){
        if(arr[i]<5) {
            arr[i] = 5;
            return;
        }
    }
}
double Find(){
    double ans = 0;
    for(int i=0; i<n; i++){
        ans += arr[i];
    }
    return round(ans/n);
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int ans = 0;
    while(true){
        if(Find()==5){
            cout<<ans<<endl;
            return 0;
        }
        inc();
        ans++;
    }
    return 0;
}

