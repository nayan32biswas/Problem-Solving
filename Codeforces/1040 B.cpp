#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int main() {
    int n, k;
    cin>>n>>k;
    int jump=(k*2)+1;
    int remain = n%jump;
    if(remain==0){
        int mid = jump/2+1;
        for(int i=0; i<n; i+=jump, mid+=jump){
            ans.push_back(mid);
        }
    }
    else {
        int mid = max(remain-k, 1);
        ans.push_back(mid);
        mid += jump;
        for(int i=mid-k; i<n; i+=jump, mid+=jump){
            ans.push_back(mid);
        }
    }

    cout<<ans.size()<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}
