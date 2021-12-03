#include <bits/stdc++.h>
using namespace std;
#define Size 10000
#define sub 5
void Insertion(vector<int>&A, int n){
    for(int j=1; j<n; j++){
        int key = A[j], i = j-1;
        while(i>=0 && A[i]>key)
            A[i+1] = A[i--];
        A[i+1] = key;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) && n!=0){
        int ans = 0;
        set<vector<int>>Set;
        for(int i=0; i<n; i++){
            vector<int>arr(sub);
            for(int j=0; j<sub; j++){
                scanf("%d", &arr[j]);
            }
            Insertion(arr, sub);
            Set.insert(arr);
        }

        cout<<Set.size()<<endl;
    }
    return 0;
}

