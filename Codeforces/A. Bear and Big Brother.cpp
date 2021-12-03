#include <iostream>
using namespace std;
int main()
{
    long long ans=0, a, b;
    cin>>a>>b;
    while(a<=b){
        a*=3;
        b*=2;
        ans++;
    }
    cout<<ans<<endl;
}
