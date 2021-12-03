#include <iostream>
using namespace std;
int main()
{
    int k, r, i=1;
    cin>>k>>r;
    long long sum=k;
    while(true) {
        if(sum%10==0 || sum%10==r) {
            cout<<i<<endl;
            return 0;
        }
        sum+=k;
        i++;
    }
}
