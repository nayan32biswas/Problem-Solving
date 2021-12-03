#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, value, i, x;
    cin>>N>>value;
    for(i=1; i<=N; i++) {
        cin>>x;
        if(x>value) break;
    }
    cout<<i<<endl;
    return 0;
}
