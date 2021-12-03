#include <iostream>
using namespace std;
int main()
{
    string c;
    cin>>c;
    if(c[0]>90) c[0] = c[0]-32;
    cout<<c;
    return 0;
}
