#include <bits/stdc++.h>
using namespace std;
#define Size 1000
set<int>S;
int main()
{
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x){
            S.insert(x);
        }
    }
    cout<<S.size()<<endl;
    return 0;
}
