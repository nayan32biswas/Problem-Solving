#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, X=0, Y=0;
    cin>>n;
    vector<pair<int, int> > arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i].first>>arr[i].second;
        arr[i].first+=1000;
        arr[i].second+=1000;
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            X = max(X, abs(arr[i].first-arr[j].first));
            Y = max(Y, abs(arr[i].second-arr[j].second));
        }
    }
    if(X*Y==0)
        return puts("-1"), 0;
    cout<<X*Y<<endl;
    return 0;
}
