#include <iostream>
using namespace std;
int main()
{
    int n, i, J, temp;
    cin>>n;
    temp = n;
    for(i=1; i<=n; i++) {
        for(J=i; J<n; J++)cout<<' ';
        for(J=0; J<i; J++) cout<<'#';
        cout<<endl;
        temp--;
    }
    cout<<endl;
}
