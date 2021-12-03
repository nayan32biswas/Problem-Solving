#include <bits/stdc++.h>
using namespace std;
#define Size 100
pair<int, pair<int, int > >arr[Size];
int main()
{
    //freopen("input.txt", "r", stdin);
    int pos=1, n;
    map<int, int>mark;
    cin>>n;
    for(int i=0; i<(n/2); i++){
        cin>>arr[i].first;
    }
    sort(arr, arr+(n/2));
    for(int i=0; i<(n/2); i++){
        arr[i].second.first=pos;
        arr[i].second.second=pos+1;
        pos += 2;
    }
    int even=0, odd=0;
    for(int i=0; i<(n/2); i++){
        odd += abs(arr[i].first-arr[i].second.first);
        even += abs(arr[i].first-arr[i].second.second);
        //cout<<arr[i].first<<" "<<arr[i].second.first<<" "<<arr[i].second.second<<endl;
    }
    cout<<min(odd, even)<<endl;
    return 0;
}
