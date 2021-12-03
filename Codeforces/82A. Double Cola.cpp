#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main()
{
    int n, ans, i, J, k;
    cin>>n;
    i=5, J=5, k=1;
    for(; i<n; J*=2, i+=J , k*=2);
    i-=J;
    for(J=0; J<5; J++) {
        i+=k;
        if(i>=n){
            cout<<s[J]<<endl;
            return 0;
        }
    }
    cout<<i<<endl;
    return 0;
}
