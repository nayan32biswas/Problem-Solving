#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp;
    bool b=true;
    cin>>n;
    for(int i=2; i<n; i++){
        temp = pow(n, 1/i);
        cout<<temp<<endl;
        if(n%temp==0) break;
    }

    return 0;
}
