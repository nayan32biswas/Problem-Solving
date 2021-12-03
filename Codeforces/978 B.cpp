#include <bits/stdc++.h>
using namespace std;
#define Size 100
int arr[Size];
int main() {
    int n;
    string str;
    cin>>n;
    cin>>str;
    int coun=0, ans=0;
    for(auto it : str) {
        if(it=='x') {
            coun++;
        } else {
            ans += max(0, coun-2);
            coun = 0;
        }
    }
    ans += max(0, coun-2);
    cout<<ans<<endl;
    return 0;
}

