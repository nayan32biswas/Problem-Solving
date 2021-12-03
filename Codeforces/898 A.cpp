#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x = n%10;
    n/=10;
    if(x>5) n++;
    cout<<n*10<<endl;
    return 0;
}
