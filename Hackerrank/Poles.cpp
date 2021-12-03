#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[5009];
int n, Max_cost[5009];
vector<long long>vec;

bool binary(int key) {
    int start=0, End=(vec.size()-1), mid;
    while(start<=End) {
        mid = (start+End)/2;
        if(vec[mid]==key) return true;
        else if(vec[mid]<key) End=mid-1;
        else start = mid+1;
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int i, J, k, temp, len;
    long long sum, ans;
    cin>>n>>k;
    for(i=0; i<n; i++){
        scanf("%d%d", &arr[i].first, &arr[i].second);
        Max_cost[i]=arr[i].second;
    }

    if(k==(n-1)) {
        int pos=0, ans=LONG_LONG_MAX;
        for(i=1; i<n; i++){
            sum = (arr[i].first-arr[i-1].first)*arr[i].second;
            if(sum<ans){
                ans = sum;
                pos=i;
            }
        }
        for(i=0; i<n; i++){
            if(i==pos || pos==(i+1))continue;
            ans+=arr[i].second;
        }
        cout<<ans<<endl;
    }
    else if(k==1){
        for(i=1, ans = 0; i<n; i++){
            ans += (arr[i].first-arr[0].first)*arr[i].second;
        }
        cout<<ans<<endl;
    }

    else{
        sort(Max_cost, Max_cost+n);
        temp = k-1;
        for(i=n-1; temp>0; i--){
            vec.push_back(Max_cost[i]);
            temp--;
        }

        for(i=(n-1), ans=0; i>=0; i--) {
            if(binary(arr[i].second)==true) {
                for(J=i+1; J<n; J++){
                    ans+=(arr[J].first - arr[i].first)*arr[J].second;
                }
                if((n-i)==1){
                    ans+=arr[i].second;
                }
                n=i;
            }
        }
        if(n>1){
            for(J=1; J<n; J++){
                temp = arr[J].first - arr[0].first;
                if(temp<1) temp=1;
                ans+=(temp)*arr[J].second;
            }
        }
        else{
            ans += arr[0].second;
        }
        cout<<ans<<endl;
    }
    return 0;
}
