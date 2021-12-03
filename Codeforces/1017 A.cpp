#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, c, d;
    scanf("%d", &n);
    vector<pair<int, int>>arr(n);
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a += (b+c+d);
        arr[i].first = a;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(arr[i].second==0){
            for(a = arr[i].first; i<n && a==arr[i].first; i++);
            cout<<((n-i)+1)<<endl;
            return 0;
        }
    }
    return 0;
}
