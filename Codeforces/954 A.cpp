#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int n, ans = 0;
    cin>>n>>str;
    for(int i=0; i<n; i++){
        if(str[i]!=str[i+1]) i++;
        ans++;
    }
    cout<<ans<<endl;
}
