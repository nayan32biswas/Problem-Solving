#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    if(n&1) cout<<'-';
    n++;
    cout<<n/2<<endl;
    return 0;
}
