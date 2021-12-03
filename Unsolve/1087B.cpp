#include <bits/stdc++.h>
using namespace std;
unsigned long long n, k;
bool isTrue(unsigned long long x)
{
    if ((x / k) * (x % k) == n){
        return true;
    }
    // if((x / k) * (x % k)==0){
    //     puts("");
    // }
    // else{
    //     cout<<x<<" :"<<(x / k) * (x % k)<<endl;
    // }
    return false;
}
int main()
{
    cin >> n >> k;
    for (int i = n+k; ; i++)
    {
        if (isTrue(i))
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}