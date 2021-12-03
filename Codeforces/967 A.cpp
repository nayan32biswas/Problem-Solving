#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
#define Size 105
int n, s;
ppi arr[Size];

ppi incres(int H, int M, int inc){
    M += inc;
    if(M>=60){
        M -= 60;
        H++;
    }
    if(M>=60){
        M %= 60;
        H++;
    }
    return make_pair(H, M);
}
bool Find(int pos){
    ppi ans = incres(arr[pos].first, arr[pos].second, s+1); // correct
    ppi next = incres(ans.first, ans.second, s);
    if(next.first<arr[pos+1].first || (next.first<=arr[pos+1].first && next.second<arr[pos+1].second)){
        cout<<ans.first<<" "<<ans.second<<endl;
        return true;
    }
    return false;

}
int main()
{
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    ppi ans = incres(0, 0, s);
    if(ans.first<arr[0].first || (ans.first<=arr[0].first && ans.second<arr[0].second)){
        puts("0 0");
        return 0;
    }
    for(int i=0; i<n-1; i++){
        if(Find(i)) return 0;
    }
    ans = incres(arr[n-1].first, arr[n-1].second, s+1); // correct
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
