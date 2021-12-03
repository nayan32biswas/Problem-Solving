#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, T, A=INT_MAX;
    cin>>n;
    map<int, vector<int>>M;
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        M[x].push_back(i+1);
    }
    for(auto it : M){
        bool ck = true;
        for(auto it1 : it.second){
            if(ck) ck = false;
            else A = min(A, abs(it1-T));
            T = it1;
        }
        break;
    }
    cout<<A<<endl;
}
