#include <bits/stdc++.h>
using namespace std;
#define Size 1000

string Find(string str) {
    int arr[125];
    memset(arr, 0, sizeof(arr));
    string sss="";
    for(auto it : str) {
        arr[it] = 1;
    }
    for(int c='a'; c<='z'; c++) {
        if(arr[c]==1) {
            sss += char(c);
        }
    }
    return sss;
}
int main() {
    int n;
    cin>>n;
    string str;
    set<string>SET;
    for(int i=0; i<n; i++) {
        cin>>str;
        SET.insert(Find(str));
    }
    cout<<SET.size()<<endl;
    return 0;
}
