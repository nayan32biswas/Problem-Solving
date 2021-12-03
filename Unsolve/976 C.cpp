#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
ppi arr[3005];
bool cmp(ppi A, ppi B){
    if(A.second!=B.second){
        return A.first<B.first;
    }
    return A.second>B.second;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    sort(arr, arr+n, cmp);
    for(auto it : arr){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}
