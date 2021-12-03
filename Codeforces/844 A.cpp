#include <bits/stdc++.h>
using namespace std;
int arr[130];
int main()
{
    int k, k1=0;
    string s;
    cin>>s>>k;
    int i, x=0, len = s.size();
    if(len<k) {
        puts("impossible");
        return 0;
    }
    for(auto c : s) arr[c]++;
    for(i=97; i<123; i++){
        if(arr[i]>0) k1--;
    }

    cout<<max(0, k)<<endl;
    return 0;
}
