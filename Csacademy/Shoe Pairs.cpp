#include <bits/stdc++.h>
using namespace std;
pair< int, int > arr[109];
int main()
{
    int n, x, Max=0;
    char c;
    cin>>n;
    for(int i=0; i<n; i++){
        cin.ignore();
        cin>>x>>c;
        if(c=='L'){
            arr[x].first++;
        }
        else {
            arr[x].second++;
        }
        Max = max(Max, x);
    }
    int ans = 0;
    n = Max+1;
    for(int i=0; i<n; i++){
        ans+=min(arr[i].first, arr[i].second);
    }
    cout<<ans<<endl;
    return 0;
}
