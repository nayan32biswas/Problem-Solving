#include <iostream>
using namespace std;
int main()
{
    long long n, x, k;
    cin>>n>>k;
    x = n/k;
    x++;
    x*=k;
    cout<<x<<endl;
    return 0;
}
