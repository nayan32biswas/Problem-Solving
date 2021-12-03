#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, c;
    while(cin>>a>>b>>c){
        cout<<max(a, max(b, c))<<endl;
    }
    return 0;
}
