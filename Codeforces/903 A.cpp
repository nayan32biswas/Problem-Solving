#include <bits/stdc++.h>
using namespace std;
int arr[] = {1, 2, 4, 5, 8, 11};
bool is_true(int n){
    for(auto it : arr) if(n==it) return false;
    return true;
}
int main(){
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        if(is_true(x))puts("YES");
        else puts("NO");
    }
    return 0;
}
