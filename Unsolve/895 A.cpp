#include <bits/stdc++.h>
using namespace std;
#define Size 129609
int lo, hi;
int main()
{
    int n, x, m = 0, total=0;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)scanf("%d", &arr[i]);

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    lo = hi = 0;
    for(auto it : arr){
        if(lo<hi) lo+=it;
        else hi += it;
    }
    total = abs(lo-hi);
    lo = hi = 0;
    for(auto it : arr){
        if(hi<lo) hi+=it;
        else lo += it;
    }
    total = min(total, abs(lo-hi));
    cout<<total<<endl;
    return 0;
}
