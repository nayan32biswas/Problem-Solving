#include <iostream>
using namespace std;
int main()
{
    long long n, a, b, c=0, cou=0 ;
    cin>>n;
    a=1, b=2;
    while(c<=n){
        c=a+b;
        a=b;
        b=c;
        cou++;
    }
    cout<<cou<<endl;
}
