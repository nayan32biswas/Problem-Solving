#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, ans=0;
    vector<int>vec;
    for(int i=1; i<35; i++) vec.push_back(i*i);
    cin>>a>>b;
    for(auto num : vec){
        if(num>=a && num<=b) ans++;
    }
    cout<<ans<<endl;
}
