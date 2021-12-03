#include <bits/stdc++.h>
using namespace std;
#define Size 1005
typedef pair<int, int> ppi;
map<ppi, int>ans;
ppi X[Size], A[Size];
ppi make(ppi x, ppi a){

    return make_pair(x.first+a.first, x.second+a.second);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &X[i].first, &X[i].second);
    }
    for(int i=0; i<n; i++){
        scanf("%d%d", &A[i].first, &A[i].second);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[make(X[i], A[j])]++;
        }
    }
    for(auto it : ans){
        if(it.second==n){
            cout<<it.first.first<<" "<<it.first.second<<endl;
            break;
        }
    }
    return 0;
}