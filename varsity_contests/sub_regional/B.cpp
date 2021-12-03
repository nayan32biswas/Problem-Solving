#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test,n,k;
    cin >> test;
    while(test--)
    {
        cin >> n >> k;
        if(n>k+1)
        {
            puts("Kilani");
            continue;
        }
        puts( (n%2)==1 ? "Kilani" : "Ayoub");
    }
}
