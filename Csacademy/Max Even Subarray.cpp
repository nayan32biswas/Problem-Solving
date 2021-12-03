#include <bits/stdc++.h>
using namespace std;
#define Size 100009
int arr[Size];
long long Max = INT_MIN;
void oneDsum(vector<int>vec){
    long long sum=0;
    for(auto num : vec){
        sum+=num;
        Max = max(Max, sum);
        if(sum<0){
            sum = 0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    vector<int>vec;
    for(int i=1; i<n; i+=2){
        vec.push_back(arr[i]+arr[i-1]);
    }oneDsum(vec);

    vec.clear();
    for(int i=2; i<n; i+=2){
        vec.push_back(arr[i]+arr[i-1]);
    }oneDsum(vec);

    cout<<Max<<endl;
    return 0;
}
