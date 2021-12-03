#include <bits/stdc++.h>
using namespace std;
#define Size 2005
pair<int, int>arr[Size];
int main()
{
    int n, k;

    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i].first);
        arr[i].second = i+1;
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    if(k==1){
        cout<<arr[0].first<<endl<<n<<endl;
        return 0;
    }
    vector<int>ans;
    int profit = 0;
    for(int i=0; i<k; i++){
        profit += arr[i].first;
        ans.push_back(arr[i].second);
    }
    cout<<profit<<endl;
    sort(ans.begin(), ans.end());
    cout<<ans[0];
    for(int i=1; i<k; i++){
        if(i==k-1){
            cout<<" "<<n-ans[i-1];
        }
        else{
            cout<<" "<<(ans[i]-ans[i-1]);
        }
    }
    puts("");
    return 0;
}

