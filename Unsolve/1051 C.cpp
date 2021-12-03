#include <bits/stdc++.h>
using namespace std;
map<int, int>Map, nice;
int n;
int main() {
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        Map[arr[i]]++;
    }
    int i=0;
    for(auto it : Map) {
        if(it.second==1) {
            nice[i]=1;
        }
        i++;
    }
    bool check = false;
    if(nice.size()&1) {
        i=0;
        for(auto it : Map) {
            if(it.second>2) {
                nice[i]=2;
                check = true;
                break;
            }
            i++;
        }
        if(nice.size()&1){
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    int mid = nice.size()/2-check;
    for(i=0; i<n; i++){
        if(check && nice[i]==2){
            printf("A");
            mid--;
        }
        if(nice[i]==1 && mid>0){
            printf("A");
            mid--;
        }
        else if(nice[i]!=2){
            printf("B");
        }
    }
}
