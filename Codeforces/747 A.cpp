#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int n, hi;
    cin>>n;
    int i = sqrt(n);
    for(; i>=0; i--){
        if(n%i==0){
            hi = n/i;
            break;
        }
    }
    cout<<i<<' '<<hi<<endl;
    return 0;
}
