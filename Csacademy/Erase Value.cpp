#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum, ans=0, Max=0, i, num;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(i=0; i<n; i++){
        cin>>arr[i];
        ans += arr[i];
    }
    sort(arr.begin(), arr.end());
    num = sum = arr[0];
    Max = 0;
    for(i=1; i<n; i++){
        if(num==arr[i]) sum+=arr[i];
        else{
            Max = max(Max, sum);
            num = arr[i];
            sum = num;
        }
    }
    Max = max(Max, sum);
    cout<<ans-Max<<endl;
}
