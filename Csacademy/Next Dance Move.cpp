#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int x = n%10;
    if(x==0) {
        cout<<4<<endl;
        return 0;
    }
    x = x%3;
    if(x==0){
        cout<<3<<endl;
    }
    else {
        cout<<x<<endl;
    }

}
