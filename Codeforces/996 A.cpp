#include <bits/stdc++.h>
using namespace std;
int arr[] = {100, 20, 10, 5};
int main() {
    int n, ans=0;
    cin>>n;
    for(int i=0; i<4; i++) {
        if(n>=arr[i]) {
            ans += (n/arr[i]);
            n %= arr[i];
        }
    }
    cout<<ans+n<<endl;
}
