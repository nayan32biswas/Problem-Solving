#include <bits/stdc++.h>
using namespace std;
int x, h, m, pos, ans;
int arr[] = {7, 17, 27, 37, 47, 57};
bool is(){
    for(auto it : arr) if(it==m || it==h) return true;
    return false;
}
int main()
{

    cin>>x>>h>>m;
    while(!is()){
        ans++;
        m -= x;
        if(m<0) h--, m = 60+m;
        if(h<0) h = 23;
    }
    cout<<ans<<endl;

    return 0;
}
