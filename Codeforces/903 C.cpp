#include <bits/stdc++.h>
using namespace std;
#define Size 5009
vector<int> check(vector<int>arr){
    vector<int>temp;
    int value = 0;
    for(auto it : arr){
        if(value==it) temp.push_back(it);
        value = it;
    }
    return temp;
}
int main()
{
    int n, ans=0;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    while(true){
        arr = check(arr);
        ans++;
        if(arr.empty()) break;
    }
    cout<<ans<<endl;

}
