#include<iostream>
using namespace std;
int main()
{
    long long int n, k, ans;
    cin >> n >> k;
        ans=k<=(n+1)/2?(k*2)-1:(k-(n+1)/2)*2;
        cout <<ans<<endl;
}
