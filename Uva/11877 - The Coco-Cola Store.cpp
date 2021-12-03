#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, ans, temp;
    while(cin>>n && n) {
        n++;
        ans=0;
        while(n>2) {
            ans+=(n/3);
            temp = n%3;
            n/=3;
            n+=temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
