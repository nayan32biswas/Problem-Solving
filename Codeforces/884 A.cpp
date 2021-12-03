#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main()
{
    int n, t, ai, i;
    cin>>n>>t;
    for(i=1; i<=n; i++){
        cin>>ai;
        t-=abs(ai-86400);
        if(t<=0){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}
