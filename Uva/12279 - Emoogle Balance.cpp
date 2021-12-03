#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int test=1, num, ans, n;
    while(cin>>n && n)
    {
        ans = 0;
        for(int i=0; i<n; i++)
        {
            cin>>num;
            if(num<1 || num>99) ans--;
            else ans++;
        }
        printf("Case %d: %d\n", test++, ans);
    }
}
